// 353. Design Snake Game
/*
 * Design a Snake game that is played on a device with screen size height x width.
 * Play the game online if you are not familiar with the game.

The snake is initially positioned at the top left corner (0, 0) with a length of 1 unit.
You are given an array food where food[i] = (ri, ci) is the row and column position of a piece of food that the snake can eat.
When a snake eats a piece of food, its length and the game's score both increase by 1.

Each piece of food appears one by one on the screen, meaning the second piece of food will not appear until the snake eats the first piece of food.
When a piece of food appears on the screen, it is guaranteed that it will not appear on a block occupied by the snake.

The game is over if the snake goes out of bounds (hits a wall) or if its head occupies a space that its body occupies after moving
(i.e. a snake of length 4 cannot run into itself).

Implement the SnakeGame class:
    SnakeGame(int width, int height, int[][] food) Initializes the object with a screen of size height x width and the positions of the food.
    int move(String direction) Returns the score of the game after applying one direction move by the snake. If the game is over, return -1.
*/
class SnakeGame {
public:
  SnakeGame(int width, int height, vector<vector<int>>& food) {
    snakeset.insert({0, 0});
    snakeque.push_back({0, 0});
    this->width = width;
    this->height = height;
    this->food = food;
  }

  int move(string direction) {
    pair<int, int> snakeCell = snakeque.front();
    int newrow = snakeCell.first;
    int newcol = snakeCell.second;

    if (direction == "U") {
      newrow--;
    } else if (direction == "D") {
      newrow++;
    } else if (direction == "L") {
      newcol--;
    } else if (direction == "R") {
      newcol++;
    }

    pair<int, int> newHead = {newrow, newcol};
    pair<int, int> curTail = snakeque.back();

    bool boundCheck1 = newrow < 0 || newrow >= height;
    bool boundCheck2 = newcol < 0 || newcol >= width;
    bool biteself = snakeset.count(newHead) != 0 && (newHead != curTail);

    // 碰到边界了, 或者吃到了自己
    if (boundCheck1 || boundCheck2 || biteself)
      return -1;

    if (foodidx < food.size() && food[foodidx][0] == newrow && food[foodidx][1] == newcol) {
      // 吃到食物了, 更新食物索引
      foodidx++;
    } else {
      // 没有吃到, 则移出尾部的节点, 它现在不再属于蛇的一部分了. set中也要更新
      snakeque.pop_back();
      snakeset.erase(curTail);
    }

    // 将最新的头部节点加入队列头, 同时更新set
    snakeque.push_front(newHead);
    snakeset.insert(newHead);

    // 队列长度 - 1就是当前的分数. -1是因为初始状态下长度为1此时计分是0
    return snakeque.size() - 1;
  }
private:
  deque<pair<int, int>> snakeque;  // 双端队列, 保存当前的所有点
  set<pair<int, int>> snakeset;    // set用来判断是否会吃到自己
  int width = 0;
  int height = 0;
  int foodidx = 0;
  vector<vector<int>> food;
};
