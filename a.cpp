#include <iostream>
#include <random>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int count = 4 * 1e4;

int a[count];

void swap(int &x, int &y) {
  int p = x;
  x = y;
  y = p;
}

void bubble() {
  for(int i = 0; i < count; i++) {
    for (int j = i; j < count; j ++) {
      if (a[i] > a[j]) {
        swap(a[i], a[j]);
      }
    }
  }
}

void clever_bubble() {
  // bool swapped;
  for (int i = 0; i < count; i ++) {
    // swapped = false;
    for (int j = 0; j < count - i - 1; j ++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
        // swapped = true;
      }
    }
    // if (!swapped) {
    //   break;
    // }
  }
}

void while_sort() {
  int i = 0;
  while (i < count) {
    for (int j = i; j < count; j ++) {
      if (a[i] > a[j]) {
        swap(a[i], a[j]);
      }
    }
    i ++;
  }
}

int main()
{
  srand(time(0));
  
  for (int i = 0; i < count; i ++) {
    a[i] = rand();
  }

  int start = clock();


  // bubble();
  clever_bubble();
  // while_sort();

  cout << (clock() - start) / 1000.f << "ms\n";

  for (int i = 0; i < count; i ++) {
    // cout << a[i] << "\n";
  }

  cout << count << " count of elements\n";

  return 0;
}
