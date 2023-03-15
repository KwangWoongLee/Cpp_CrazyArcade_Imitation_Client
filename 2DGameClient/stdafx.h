// �̸� �����ϵ� ����Դϴ�.
#pragma once

#define WIN32_LEAN_AND_MEAN // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.



#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "mswsock.lib")
#pragma comment(lib, "Winmm.lib")
#pragma comment(lib, "dbghelp.lib")


#ifdef _DEBUG
#pragma comment(lib, "ServerCore\\Debug\\ServerCore.lib")
#else
#pragma comment(lib, "ServerCore\\Release\\ServerCore.lib")
#endif

#pragma comment(lib, "SDL2\\SDL2.lib")
#pragma comment(lib, "SDL2\\SDL2main.lib")
#pragma comment(lib, "SDL2\\SDL2_image.lib")
#define NOMINMAX

// ������ ����
#include <Ws2tcpip.h>
#include <winsock2.h>
#include <mswsock.h>
#include <Mmsystem.h>
#include <Ws2spi.h>
#include <Mstcpip.h>
#include <windows.h>
#include <cassert>

// std
#include <iostream>
#include <stdexcept>
#include <format>
#include <memory>
#include <thread>
#include <string>
#include <algorithm>
#include <functional>

#include <fstream>
#include <iostream>
#include <sstream>

//�ڷᱸ��
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <atomic>

//SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_image.h>


#include "ServerCore/CorePch.h"

#include "Math.h"
#include "Vector2.h"
#include "Singleton.h"

#include "GameTypes.h"
#include "RedisManager.h"

#include "InputManager.h"

#include "Actor.h"
#include "Component.h"
#include "SpriteComponent.h"
#include "AnimationComponent.h"
#include "BlockComponent.h"

#include "Boom.h"
#include "Bomb.h"
#include "Player.h"
#include "Block.h"

#include "Game.h"
