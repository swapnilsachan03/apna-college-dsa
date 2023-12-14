// https://www.geeksforgeeks.org/introduction-to-heap-data-structure-and-algorithm-tutorials

#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
  int* arr;
  int maxSize;
  int heapSize;

  public:
    MaxHeap (int size) {
      maxSize = size;
      heapSize = 0;
      arr = new int[maxSize];
    }

    int parent (int i) {
      return (i-1) / 2;
    }

    int lChild (int i) {
      return 2 * i + 1;
    }

    int rChild (int i) {
      return 2 * i + 2;
    }

    int getMax() {
      return arr[0];
    }

    int currSize() {
      return heapSize;
    }

    void insertKey (int x) {
      if (heapSize == maxSize) {
        cout << "Heap overflow - could not insert key \n";
        return;
      }

      heapSize += 1;
      int i = heapSize - 1;
      arr[i] = x;

      while (i != 0 && arr[parent(i)] < arr[i]) {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
      }
    }

    void updateKey (int i, int val) {
      arr[i] = val;

      while (i != 0 && arr[parent(i)] < arr[i])
      {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
      }
    }

    int removeMax () {
      if (heapSize <= 0) return INT32_MIN;

      if (heapSize == 0) {
        heapSize -= 1;
        return arr[0];
      }

      int root = arr[0];
      arr[0] = arr[heapSize - 1];
      heapSize -= 1;

      maxHeapify(0);

      return root;
    }

    void deleteKey (int i) {
      updateKey(i, INT_MAX);
      removeMax();
    }

    void maxHeapify (int i) {
      int l = lChild(i);
      int r = rChild(i);
      int largest = i;

      if (l < heapSize && arr[l] > arr[i])
        largest = l;
      
      if (r < heapSize && arr[r] > arr[i])
        largest = r;

      if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(largest);
      }
    }
};

int main()
{
  MaxHeap mh(15);

  cout << "Entered 6 keys :- 3, 10, 12, 8, 2, 14 \n \n";

  mh.insertKey(3);
  mh.insertKey(10);
  mh.insertKey(12);
  mh.insertKey(8);
  mh.insertKey(2);
  mh.insertKey(14);

  cout << "The current size of the heap is: " << mh.currSize() << endl;
  cout << "The current maximum element is: " << mh.getMax() << endl;

  mh.deleteKey(2);

  cout << "The current size of the heap is: " << mh.currSize() << endl;

  mh.insertKey(15);
  mh.insertKey(5);

  cout << "The current size of the heap is: " << mh.currSize() << endl;
  cout << "The current maximum element is: " << mh.getMax() << endl;

  return 0;
}
