#include <iostream>
#include <vector>
using namespace std;
void quickSort(int, int, int []);

int main(){
  int N;//, k = 0;

  cout << "정렬할 수 갯수 : ";
  cin >> N;
  //cin >> k;

  cout << "\n정렬 전 : ";
  int quickTest[N];
  for(int i = 0; i<N; i++){
    int x;
    cin >>x;
    quickTest[i] = x;
  }

  quickSort(0, N-1, quickTest);

cout << "\n정렬 후 : ";  
  for(int i = 0; i<N; i++)
    cout <<quickTest[i] << " ";

  // cout << quickTest[N-k];
  
  return 0;
}

void quickSort(int i, int j, int quick[]){
  // cout << endl;
  if(i>=j) return; //원소가 1개
  int pivot = i; //맨 앞의 숫자를 pivot 설정

  int left = i+pivot; //왼쪽 출발 지점
  int right = j; //오른쪽 출발 지점

  
  while(left<=right){ //왼쪽 오른쪽 기준 엇갈리기 전가지
    while(left <= right && quick[left]<=quick[pivot]) left++;  //1. 피봇을 제외한 처음 원소(left) 부터 피봇보다 큰 값을 찾기
    while(right > left && quick[right] >= quick[pivot]) right--; //1. 끝(right)에서부터 피봇보다 작은 값을 찾기.

    //찾았다!(피봇보다 큰 왼쪽 값, 작은 오른쪽 값을..)
    if(left<=right){ //엇갈리지 않은 상태
      int tmp = quick[left]; //큰 왼쪽과 작은 오른쪽 교체
      quick[left] = quick[right];
      quick[right] = tmp;
    }else{ //찾았는데 왼쪽 오른쪽 엇갈렸다면?
      int tmp = quick[right]; //피봇과 오른쪽 값 교체
      quick[right] = quick[pivot];
      quick[pivot] = tmp;
    }
  }

  // for(int i = 0; i<5; i++)
  //   cout << quick[i] << " ";
  quickSort(i, right-1, quick);
  quickSort(right+1, j, quick);
}