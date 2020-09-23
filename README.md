# Algorithm for coding test

<img src="./1.gif" width="400" height="400" />

---


1. [BOJ_14502_연구소](#1-BOJ_14502_연구소)
2. [BOJ_19235_모노미노도미노](#2-BOJ_19235_모노미노도미노)
3. [SWEA_1285_행렬찾기](#3-SWEA_1825_행렬찾기)
4. [BOJ_17825_주사위 윷놀이](#4-BOJ_17825_주사위-윷놀이)
5. [BOJ_17142_연구소3](#5-BOJ_17142_연구소3)
6. [BOJ_17822_원판돌리기](#6-BOJ_17822_원판돌리기)
7. [BOJ_17779_게리멘더링](#7-BOJ_17779_게리멘더링)
8. [SWEA_1767_프로세서 연결하기](#8-SWEA_1767_프로세서-연결하기)
9. [BOJ_19237_어른상어](#9-BOJ_19237_어른상어)
10. [BOJ_19238_스타트 택시](#10-BOJ_19238_스타트-택시)
11. [BOJ_17837_새로운 게임](#11-BOJ_17837_새로운-게임)
12. [BOJ_17143_낚시왕](#12-BOJ_17143_낚시왕)
13. [BOJ_13460_구슬 탈출2](#13-BOJ_13460_구슬-탈출2)
14. [BOJ_1697_숨바꼭질](#14-BOJ_1697_숨바꼭질)
15. [BOJ_13460_테트로미노](https://www.acmicpc.net/problem/13460)
16. [BOJ_1697_친구네트워크](https://www.acmicpc.net/problem/1697)
17. [BOJ_14501_퇴사](https://www.acmicpc.net/problem/14501)
18. [BOJ_14502_로봇 청소기](https://www.acmicpc.net/problem/14502)
19. [PROG_컬러링북](https://programmers.co.kr/learn/courses/30/lessons/1829)
20. [PROG_자물쇠와 열쇠](https://programmers.co.kr/learn/courses/30/lessons/60059)
21. [SWEA_5658_보물상자 비밀번호](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRUN9KfZ8DFAUo&categoryId=AWXRUN9KfZ8DFAUo&categoryType=CODE)
22. [BOJ_14890_경사로](#22-BOJ_14890_경사로)
23. [SWEA_5550_나는 개구리로소이다](#23-SWEA_5550_나는-개구리로소이다)<br>
24. [BOJ_14891_톱니바퀴](#24-BOJ_14891_톱니바퀴)<br>
25. [BOJ_15683_감시](#25-BOJ_15683_감시)<br>
26. [PROG_42884_단속카메라](#26-PROG_42884_단속카메라)<br>
27. [SWEA_5648_원자소멸 시뮬레이션](#27-SWEA_5648_원자-소멸-시뮬레이션)<br>
28. [BOJ_15684_사다리조작](#28-BOJ_15684_사다리조작)<br>
29. [PROG_42628_이중우선순위큐](#29-PROG_42628_이중우선순위큐)<br><br><br>

### 1. [BOJ_14502_연구소](https://www.acmicpc.net/problem/14502)<br>
[코드](./BOJ_연구소.cpp)<br>
시간 : 24ms

BFS와 DFS를 사용하여 안전영역의 최댓값을 구하였다.<br>

1. 최댓값을 구해야 되므로 DFS를 사용해야겠다고 생각했다.<br>
2. 바이러스가 퍼지기 때문에 BFS를 사용해야겠다고 생각했다.<br><br>

사실 이 문제 처음 풀었을 때는 시간이 432ms가 나왔다. (문제의 input size가 더 컸다면 시간초과가 나왔을 것이다.)<br>
아래와 같은 방법으로 수정하니 시간을 24ms까지 줄일 수 있었다. <br>
* DFS를 visited 배열을 사용해 이미 체크한 곳은 다시 방문하지 않도록 구현.<br>
 ( 이 부분에서 시간을 가장 많이 줄일 수 있었음) <br>
* DFS도 재귀가 아닌 3중 for문을 사용해 구현할 수 있었다. <br>
* BFS 함수에서 Queue 대신 array 사용 <br><br>

#### 예전에는 문제만 풀면 되는 줄 알았는데 실행시간도 매우 중요하다고 한다. <br>
앞으로는 위에서 언급한 부분들도 잘 신경써가면서 풀어야겠다.<br><br><br>



### 2. [BOJ_19235_모노미노도미노](https://www.acmicpc.net/problem/19235)<br>
[코드](./BOJ_모노미노도미노.cpp)<br>
시간 : 8ms

완전 시뮬레이션 문제.<br>
조건만 잘 따져주면 풀 수 있는 문제.<br>
근데 그 조건 따지는게 정말정말 어려운 문제<br><br>

row or column이 가득찬 경우 해당 행,열을 삭제하므로 블록이 나누어질 수 있다.<br>
이 경우를 제외하고는 블록이 나누어질 수 없다.<br>
이 부분을 따져주지 않아서 계속 틀렸었다.<br><br><br>


### 3. [SWEA_1825_행렬찾기](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV18LoAqItcCFAZN&categoryId=AV18LoAqItcCFAZN&categoryType=CODE)<br>
[코드](./SWEA_행렬찾기.cpp)<br>
시간 : 21ms <br><br>

행과 열의 개수를 구하는 문제<br>
크기가 작은 행렬부터 출력을 해주는데 만약 크기가 같으면 row 개수가 더 작은 순서대로 출력<br>
이 부분 어떻게 해야될 지 몰라서 bubble sort로 풀었다. <br>
종현오빠가 '**비트 마스크**'라는 걸 알려주셔서 정말정말 간단하게 풀 수 있었다. <br>
비교 조건이 2가지 이상일 때 사용하면 좋다 <br>

        int score =(total << 10)+(row << 5) + col ;
        
비교 조건이 전체 크기를 기준으로 먼저 따져주므로 total에는 1024를 곱해주고, 두번째 조건인 row의 개수에 32를 곱해주어 전체 점수를 구할 수 있다.<br>
또한 곱셈 연산자보다 shift 연산이 훨씬 빠르므로 시간도 줄일 수 있다. <br><br><br>

### 4. [BOJ_17825_주사위 윷놀이](https://www.acmicpc.net/problem/17825)<br>
[코드](./BOJ_주사위윷놀이.cpp)<br>
시간 : 12ms <br><br>

문제 조건도 별로 없어서 금방 풀 줄 알았지만 며칠동안 고민했다.<br>
문제 조건도 잘못 이해했었다.<br><br>

1. 움직인 칸에 다른 말이 존재한다면 해당 조합은 아예 무효 ( 움직이지 않는다.) <br>
2. 40의 경우 두 가지 경로에서 올 수 있다.<br>
3. 게임판에 30은 2개 존재<br><br><br>





### 5. [BOJ_17142_연구소3](https://www.acmicpc.net/problem/17142)<br>
[코드](./BOJ_연구소3.cpp)<br>
시간 : 12ms <br><br>


BFS와 DFS를 사용하는 문제.<br><br>
DFS로 M개 만큼 활성화 시킬 바이러스를 선택한 뒤<br>
BFS로 바이러스를 퍼뜨리면 된다.<br><br>
위와 같은 방법으로 풀었는데 예제는 다 잘 돌아가지만 계속 시간초과가 발생했다.<br>
처음에는 M개만큼 활성화 시킬 바이러스를 선택한 뒤 BFS 함수에서 하나씩 queue에 넣어줘서 풀었다. <br>
그러면 이미 방문했 던 위치도 다시 확인하게 되는데 이것 때문에 시간 초과가 나온 것 같다. <br><br>
#### 그래서 DFS에서 애초에 활성화 시킬 바이러스만 queue에 먼저 push 하고 BFS 함수 호출을 했다.<br>
이렇게 풀면 재방문 하지 않아도 해당 좌표에 먼저 도착한 게 최소 값이므로 시간 초과가 발생하지 않는다.<br>


    if(cnt == M)
    {   
        for(int i=0;i<v.size() ; i++){
            
            if(visited[i] ==1 ){
                q.push(make_pair(v[i].first,v[i].second));
                tm[v[i].first][v[i].second] = 0;
            }
        }
        BFS();
        return ;
    }


<br><br><br>



### 6. [BOJ_17822_원판돌리기](https://www.acmicpc.net/problem/17822)<br>
[코드](./BOJ_원판돌리기.cpp)<br>
시간 : 4ms <br><br>


시뮬레이션 문제로 문제 조건만 잘 따져주면서 풀면 된다.<br>
모듈화 해서 풀었더니 훨씬 코드가 깔끔하고 디버깅 할 때도 확인하기 쉽다.<br><br>
1. 원판의 번호가 x의 배수인 원판들 회전<br>
2. 인접한 수가 같은 것들을 0으로 바꿔준다. <br>
  ( 이 때 다른 인접한 부분과도 같을 수 있으므로 0으로 바꿔 줄 부분을 tmp 배열에 표시해놓고 모든 원판에 대해 확인해준뒤 map을 update ) <br>
3. 만약 같은 수가 존재하지 않는다면 모든 원판에 대해 평균을 구하고 평균보다 작은 값들은 +1 ,큰 값들은 -1을 해준다.<br>
 평균 구할 때 아래와 같이 하면 <br>

#### sum과 cnt가 int형 변수이므로 avg도 double형이 아니라 int 형이 된다. <br>

 
    double avg = sum/cnt;
 
 
 따라서 아래와 같이 해줘야 된다. ( 이 부분에서 틀렸었다..)<br>

    double avg = double(sum) / double(cnt);

<br><br><br>



### 7. [BOJ_17779_게리멘더링](https://www.acmicpc.net/problem/17779)<br>
[코드](./BOJ_게리맨더링2.cpp)<br>
시간 : 20ms <br><br>

시뮬레이션 + DFS 문제<br>
문제 조건 잘 따져가면서 지역 인구 차이의 최솟값을 구해주면 된다.<br>
1. 4중 for문 사용해서 x,y,d1,d2 값 구하기<br>
2. 이차원 배열 하나 선언해서 좌표 값을 기준으로 구역을 나눠준다.<br>
3. 구역별로 인구의 총 합을 구해서 인구 차이의 최솟값을 구해준다.<br>
<br><br><br>



### 8. [SWEA_1767_프로세서 연결하기](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV4suNtaXFEDFAUf)

[코드](./SWEA_프로세스연결.cpp)<br>


처음에는 문제 너무 단순하게 생각해서 DFS로 모든 경우 다 따져가면서 전선의 길이가 최소가 되는 값을 찾는 방법으로 풀었다. <br>
벡터에 프로세서 좌표를 저장하고 각 프로세서마다 모든 방향을 다 따져준다. <br>
물론 당연히 '시간초과'가 나온다. <br><br>
생각해보니 연결이 안되는 프로세서도 있다는 조건을 빼먹었다. <br>
이 부분을 어떻게 처리할지에 있어서 많은 시간을 쓴 것 같다. <br>
map의 값을 update 하기 전에 연결을 할 수 있는 프로세서인지 확인을 해준다. <br>
만약 연결을 할 수 있는 프로세서라면 map의 값을 0 -> 1로 update 해주고 다음 DFS 호출 <br>
연결을 못한다 해도 다음 DFS는 호출해줘야 된다.<br>
다만 인자 값에서 차이를 두어 구분한다. ( 연결할 수 있는 경우 연결된 프로세서의 개수를 +1하여 DFS 호출 )  <br>
또한 DFS 함수가 끝나 다시 돌아올 경우 map의 값을 다시 0 -> 1로 update 해줘야된다. <br><br><br>



### 9. [BOJ_19237_어른상어](https://www.acmicpc.net/problem/19237)<br>
[코드](./BOJ_어른상어.cpp)<br>
시간 : 4ms <br><br>

시뮬레션문제로 조건만 잘 따져주면 되는데/...<br>

예를 들어 2번 상어가 자신의 향수가 남아있는 곳으로 이동하고<br>
3번 상어도 그 자리로 이동하려고 하면 3번이 쫓겨난다.<br>
애초에 3번은 그 자리를 갈 수 없다. ( 2번 향수가 있었으므로 )<br>
근데 시간을 2번에서 update 해줘서 새로 들어온걸로 된다. =>  tm_tmp 배열 사용해서 이전에 이미 존재했는지 확인<br>

(이렇게 쓰니까 뭔소린지 모르겠네 그림 추가해야겠다.)
(배옅 3개 써서 현재 존재하는 상어, 시간, 향수뿌린 상어 번호 , 따로 저장했느데 struct 사용하는 걸로 바꿔봐야지)  <br><br><br>


### 10. [BOJ_19238_스타트 택시](https://www.acmicpc.net/problem/19238)<br>
[코드](./BOJ_스타트택시.cpp)<br>
시간 : 8ms ( 근데 같은 코드 2번 제출했는데 하나는 4ms, 다른 하나는 8ms 나옴..뭐지) <br><br>

BFS 사용해서 풀 수 있는 문제.<br>

현재 택시를 기준으로 가장 가까운 거리에 있는 손님을 태워야 된다.<br>
만약 거리가 동일한 손님이 여려명이라면 그중 행 번호가 가장 작은 손님을, 그런 손님이 여러 명이면 그중 열 번호가 가장 작은 손님을 먼저 태운다.<br><br>
이 부분이 비트 마스크를 몰랐다면 복잡하게 풀었을텐데 <br>
비트 마스크를 사용하여 최단거리를 기준으로 먼저 따져둔 뒤, 최단거리가 같다면 행과 열로 구한 score를 기준으로 비교하여 간단하게 풀 수 있었다.<br>
(이렇게 비교 조건이 2가지 이상일 때 사용하면 좋다.)<br>

        person[i].score = ( person[i].sx  << 10 ) + ( person[i].sy << 5 );


<br><br>

### 11. [BOJ_17837_새로운 게임](https://www.acmicpc.net/problem/17837)<br>
[코드](./BOJ_새로운게임.cpp)<br>
시간 : <br>
제발 맞고싶다..어느 부분을 놓친건지 전혀 모르겠음
<br><br><br>

### 12. [BOJ_17143_낚시왕](https://www.acmicpc.net/problem/17143)<br>
[코드](./BOJ_낚시왕.cpp)<br>
시간 : 52ms<br>

처음에는 시간초과가 나왔다.<br>
어느 부분에서 나오는지 몰라 구글링 해봤는데 상어를 이동하는 부분 때문에 시간초과가 발생한 것 같다.<br><br>

#### 처음에는 상어의 주어진 속력만큼 for문을 돌아 한칸씩 이동했는데<br>
#### dx, dy에 속력을 곱하여 한번에 이동하면 된다. <br>

앞으로 속력이 주어진 경우 이러한 방법으로 움직여야겠다. <br><br><br>


### 13. [BOJ_13460_구슬 탈출2](https://www.acmicpc.net/problem/13460)<br>
[코드](./BOJ_구슬탈출2.cpp)<br>
시간 : 0ms<br>

처음에는 DFS로 풀었더니 92ms가 나왔다.<br>
생각해보니 최솟값을 구하는 문제이니 cnt 값을 1씩 증가시키며 visited 배열로 중복 처리 해주면서 BFS를 사용해 풀 수 있다.<br>

DFS를 사용하는 경우 cnt가 10이 될 때까지 모든 가능한 경우에 대해서 다 확인하고 그 중 최솟값을 구하는데 <br>
BFS를 사용하는 경우 cnt가 1씩 증가하며 빨간 구슬이 탈출하면 그냥 게임이 끝이므로 시간이 훨씬 조금 걸린다. <br><br><br>


### 14. [BOJ_1697_숨바꼭질](https://www.acmicpc.net/problem/1697)<br>
[코드](./BOJ_숨바꼭질.cpp)<br>
시간 : 0ms<br>

BFS를 사용해 현재 수빈이의 위치에서 +1, -1, *2의 위치로 이동하면 된다.<br>
visited 배열을 사용해 이미 방문한 경우 continue를 사용해 다시 방문하지 않도로 했다.<br>
(원래 이미 방문 했어도 현재 시간보다 더 오래 걸렸다면 재방문 하도록 했는데 4ms 나왔다.)<br>
이미 한번 방문 했다면 재방문 할 필요가 없다. <br><br><br>

### 22. [BOJ_14890_경사로](https://www.acmicpc.net/problem/14890)<br>
[코드](./BOJ_경사로.cpp)<br>
시간 : 0ms<br>

시뮬레이션 문제 <br>
여러번 풀어본 문제인데 한번에 쉽게 해결하지 못했다. <br><br><br>

### 23. [SWEA_5550_나는 개구리로소이다](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWWxqfhKAWgDFAW4&categoryId=AWWxqfhKAWgDFAW4&categoryType=CODE)<br>
[코드](./SWEA_나는개구리로소이다.c)<br>
시간 : 3ms<br>

원래 cpp로 풀었을 때 6ms 나왔다.<br>
cout, cin 모두 printf, scanf로 바꿔주니까 3ms가 나왔다.<br><br><br>


### 24. [BOJ_14891_톱니바퀴](https://www.acmicpc.net/problem/14891)<br>
[코드](./BOJ_톱니바퀴.cpp)<br>
시간 : 0ms<br>

시뮬레이션 문제 <br>
회전하는 함수랑 회전시킬지 결정하는 함수 각각 구현해서 풀었다. <br><br><br>


### 25. [BOJ_15683_감시](https://www.acmicpc.net/problem/15683)<br>
[코드](./BOJ_감시.cpp)<br>
시간 : 16ms<br>

CCTV 종류에 따라 경우의 수 구해서 풀었다.<br><br><br>



### 26. [PROG_42884_단속카메라](https://programmers.co.kr/learn/courses/30/lessons/42884)<br>
[코드](./PROG_단속카메라.cpp)<br>
시간 : 0ms <br>

세상 간단한 문제 처음에 너무 복잡하게 풀었다.<br>
차량의 이동 경로 오름차순으로 정렬해주고 <br>
차량의 시작 부분이 현재 cctv의 위치보다 뒤에 있는 경우 CCTV 개수 1 증가
차량의 끝 부분이 현재 cctv의 위치보다 앞에 있는 경우 CCTV 위치만 update <br><br><br>

### 27. [SWEA_5648_원자 소멸 시뮬레이션](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRFInKex8DFAUo&categoryId=AWXRFInKex8DFAUo&categoryType=CODE)<br>
[코드](./SWEA_원자소멸시뮬레이션.cpp)<br>
사실 아직 런타임에러,, <br><br><br>

### 28. [BOJ_15684_사다리조작](https://www.acmicpc.net/problem/15684)<br>
[코드](./BOJ_사다리조작.cpp)<br>
시간 : 0ms<br>

DFS를 사용해서 사다리를 N개 추가해줬다.<br>
처음 풀었을 때 2차원 배열의 visited를 어떻게 처리해줘야 될지 몰랐다.<br>
따로 중복처리 안해주니까 560ms 나왔다.<br>
이중 for문 순서 바꾸니까 0ms로 줄었다.(열 증가 -> 행 증가 )<br>
#### visited 자료형 int 말고 bool로 하자 !<br><br><br>

### 29. [PROG_42628_이중우선순위큐](https://programmers.co.kr/learn/courses/30/lessons/42628)<br>
[코드](./PROG_이중우선순위큐.cpp)<br>
시간 : ms<br>

string 관련 함수 익숙지도록 <br>
substr, stoi 등..<br><br><br>


