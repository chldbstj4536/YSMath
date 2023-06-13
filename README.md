# YSMath
**공부하면서 만든 수학 라이브러리**

## 요구 사항
- C++20 이상 컴파일러
- [CMake][cmakelink] (3.25버전 이상)

[cmakelink]: https://cmake.org/install/

## 현제 제공하는 기능들
- Vector
- Matrix


# 라이브러리 설치 방법
YSMath 저장소를 복제한다.
```
git clone --recurse-submodules https://github.com/chldbstj4536/YSMath.git
```
저장소로 이동한다.
```
cd YSMath
```
cmake 명령어를 통해 build 폴더에 프로젝트를 생성한다.
```
cmake -S . -B build -DCMAKE_PREFIX_INSTALL=./out
```
cmake 명령어를 통해 생성된 프로젝트를 빌드하고 결과물을 out폴더에 설치한다.
```
cmake --build build --target install
```

# 라이브러리 테스트 프로젝트 생성 및 빌드 방법
라이브러리 설치 방법을 따라서 설치를 먼저 한다.

test 폴더로 이동한다
```
cd test
```

test 프로젝트를 생성한다.
```
cmake -S . -B build -DCMAKE_PREFIX_INSTALL=./../out
```
위까지 진행하면 자신의 플렛폼에 설치된 IDE에 맞게 build 폴더에 프로젝트 파일이 생성된다.

cmake 명령어를 통해 생성된 테스트 프로젝트를 빌드한다.
```
cmake --build build
```

build/Debug 폴더 안에 테스트 프로그램 실행파일이 생성되어있다.