#include <iostream>
#include <vector>
using namespace std;
void quickSort(int, int, vector<int>);

int main(){
  int N;
  cout << "정렬할 정수 갯수 N개 : ";
  cin >> N;

  cout << "\n" << "N개의 정수 입력 : ";

  vector<int> quickTest;
  quickTest.clear();
  for(int i = 0; i<N; i++){
    int x;
    cin >>x;
    quickTest.push_back(x);
  }

  cout << "\n정렬 시작 \n";
  quickSort(0, N-1, quickTest);
  cout << "정렬 끝 \n";

  return 0;
}

void quickSort(int i, int j, vector<int> quick){

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

  for(int i = 0; i<quick.size(); i++)
    cout << quick[i] << " ";

  cout << "\n";

  quickSort(i, right-1, quick);
  quickSort(right+1, j, quick);
}
