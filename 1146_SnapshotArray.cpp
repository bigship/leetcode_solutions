// 1146. Snapshot Array
/*
 * Implement a SnapshotArray that supports the following interface:

SnapshotArray(int length) initializes an array-like data structure with the given length.  Initially, each element equals 0.
void set(index, val) sets the element at the given index to be equal to val.
int snap() takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id
*/

class SnapshotArray {
public:
  SnapshotArray(int length) {

  }

  void set(int index, int val) {
    map[index] = val;
  }

  // 一旦执行snap, 就把最近修改过的状态保存进来
  int snap() {
    int retid = snapid;
    snapshot[snapid] = map;
    snapid++;
    return retid;
  }

  int get(int index, int snap_id) {
    // 找不到snap_id表示那个位置没有被修改过, 返回初始值0
    if (snapshot.find(snap_id) == snapshot.end()) {
      return 0;
    }
    // 找得到snap_id, 就返回最近修改过的状态
    return snapshot[snap_id][index];
  }
private:
  int snapid = 0;
  std::unordered_map<int, int> map;  // 记录每次修改过的状态
  std::unordered_map<int, unordered_map<int, int>> snapshot;
};


