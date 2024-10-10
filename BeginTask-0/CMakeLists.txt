cmake_minimum_required(VERSION 3.16)

project(BeginTask-0)

Include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.15.2
)

FetchContent_MakeAvailable(googletest)

add_executable(main main.cpp tests.cpp)

target_compile_options(main PRIVATE
  -Ofast               
  -march=native        
  -funroll-loops       
  # -flto                
  -fomit-frame-pointer 
  -fno-stack-protector 
  -fno-exceptions      
  -fno-rtti            
  -DNDEBUG             
  -ffast-math          
  -mavx2               
  -funroll-loops       
  -fprofile-generate   
  -fprofile-use    
)

target_link_libraries(main gtest gmock gcov)
