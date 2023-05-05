#include "pch.h"
#include "EnginePch.h"
#include "Engine.h"

//엔진 객체를 전역으로 EnginePch 에 선언해두고
//다른곳에서 모두 사용하도록
//유니크 포인터를 이용해서 안전하게
unique_ptr<Engine> GEngine = make_unique<Engine>();

