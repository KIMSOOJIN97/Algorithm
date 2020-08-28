# Algorithm for coding test



1. [BOJ_17825_주사위 윷놀이](#1-BOJ_17825_주사위-윷놀이)
2. [BOJ_19235_모노미노도미노](#2-BOJ_19235_모노미노도미노)
3. [SWEA_1285_행렬찾기](#3-SWEA_1825_행렬찾기)

---


### 1. [BOJ_17825_주사위 윷놀이](https://www.acmicpc.net/problem/17825)<br>
[코드](./BOJ_주사위윷놀이.cpp)<br>
시간 : 12ms <br><br>

문제 조건도 별로 없어서 금방 풀 줄 알았지만 며칠동안 고민했다.<br>
문제 조건도 잘못 이해했었다.<br><br>

1. 움직인 칸에 다른 말이 존재한다면 해당 조합은 아예 무효 ( 움직이지 않는다.) <br>
2. 40의 경우 두 가지 경로에서 올 수 있다.<br>
3. 게임판에 30은 2개 존재<br><br><br>

### 2. [BOJ_19235_모노미노도미노](https://www.acmicpc.net/problem/19235)<br>
[코드](./BOJ_모노미노도미노.cpp)<br>
시간 : 8ms

완전 시뮬레이션 문제.<br>
조건만 잘 따져주면 풀 수 있는 문제.<br>
근데 그 조건 따지는게 정말정말 어려운 문제<br><br><br>


### 3. [SWEA_1825_행렬찾기](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV18LoAqItcCFAZN&categoryId=AV18LoAqItcCFAZN&categoryType=CODE)<br>
[코드](./SWEA_행렬찾기.cpp)<br>
시간 : 21ms <br><br>

행과 열의 개수를 구하는 문제<br>
크기가 작은 행렬부터 출력을 해주는데 만약 크기가 같으면 row 개수가 더 작은 순서대로 출력<br>
이 부분 어떻게 해야될 지 몰라서 bubble sort로 풀었다. <br>
종현오빠가 '비트 마스크'라는 걸 알려주셔서 정말정말 간단하게 풀 수 있었다. <br>
비교 조건이 2가지 이상일 때 사용하면 좋다 <br>

        int score =(total << 10)+(row << 5) + col ;
        
비교 조건이 전체 크기를 기준으로 먼저 따져주므로 total에는 1024를 곱해주고, 두번째 조건인 row의 개수에 32를 곱해주어 전체 점수를 구할 수 있다.<br>
또한 곱셈 연산자보다 shift 연산이 훨씬 빠르므로 시간도 줄일 수 있다. <br><br><br>
