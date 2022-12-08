#include <iostream>
#include <vector>

using namespace std;

void quickSort(int *, int, int);

int main() {
	 ios::sync_with_stdio(false);
	int N;
	cin >> N;
	
	int data[N];
	for(int i = 0; i<N; i++)
		cin >> data[i];
		
	int len = sizeof(data)/sizeof(*data);
  	quickSort(data, 0, len-1);

  for (int i = 0; i < len; i++){
  	cout << data[i];
  	if(i != len-1)
  		cout << "\n";
  }

  return 0;
}

void quickSort(int *data, int start, int end) {
  if (start >= end) return;
  int pivot = start;  // 기준 값
  int i = start + 1;
  int j = end;

  while (i <= j) {
    while (data[i] <= data[pivot])  // 키 값보다 큰 값 만날때까지 오른쪽으로 이동
      i++;
    while (data[j] >= data[pivot] &&j > start)  // 키 값보다 작은 값 만날 때까지 왼쪽으로 이동
      j--;
      
    if (i > j)  //현재 엇갈린 상태면 pivot 값 교체
    {
      int temp = data[j];
      data[j] = data[pivot];
      data[pivot] = temp;
    } else {
      int temp = data[j];
      data[j] = data[i];
      data[i] = temp;
    }

    quickSort(data, start, j - 1);
    quickSort(data, j + 1, end);
  }
}
