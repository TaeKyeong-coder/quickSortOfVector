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
  int pivot = start;  // ���� ��
  int i = start + 1;
  int j = end;

  while (i <= j) {
    while (data[i] <= data[pivot])  // Ű ������ ū �� ���������� ���������� �̵�
      i++;
    while (data[j] >= data[pivot] &&j > start)  // Ű ������ ���� �� ���� ������ �������� �̵�
      j--;
      
    if (i > j)  //���� ������ ���¸� pivot �� ��ü
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
