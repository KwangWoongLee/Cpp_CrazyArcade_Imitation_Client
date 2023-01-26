// 미리 컴파일된 헤더입니다.
#pragma once

#define WIN32_LEAN_AND_MEAN // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.



#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "mswsock.lib")
#pragma comment(lib, "Winmm.lib")
#pragma comment(lib, "dbghelp.lib")


#ifdef _DEBUG
#pragma comment(lib, "ServerCore\\Debug\\ServerCore.lib")
#pragma comment(lib, "Protobuf\\Debug\\libprotobufd.lib")
#else
#pragma comment(lib, "ServerCore\\Release\\ServerCore.lib")
#pragma comment(lib, "Protobuf\\Release\\libprotobuf.lib")
#endif

#pragma comment(lib, "SDL2\\SDL2.lib")
#pragma comment(lib, "SDL2\\SDL2main.lib")
#pragma comment(lib, "SDL2\\SDL2_image.lib")
#define NOMINMAX

// 윈도우 관련
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

//자료구조
#include <iostream>
#include <vector>
#include <unordered_map>
#include <atomic>

//SDL
#include <SDL.h>
#include <SDL_scancode.h>
#include <SDL_image.h>


#include "CorePch.h"


using ClientServiceRef = shared_ptr<class ClientService>;
using ServerSessionRef = shared_ptr<class ServerSession>;
using ComponentRef = shared_ptr<class Component>;
using SpriteComponentRef = shared_ptr<class SpriteComponent>;
using CollisionComponentRef = shared_ptr<class CollisionComponent>;
using AnimationComponentRef = shared_ptr<class AnimationComponent>;
using InputComponentRef = shared_ptr<class InputComponent>;
using BlockComponentRef = shared_ptr<class BlockComponent>;
using ActorRef = shared_ptr<class Actor>;
using PlayerRef = shared_ptr<class Player>;
using BombRef = shared_ptr<class Bomb>;
using BoomRef = shared_ptr<class Boom>;
using TileRef = shared_ptr<class Tile>;

#include "Math.h"
#include "Vector2.h"
#include "Input.h"
#include "Singleton.h"

#include "Actor.h"
#include "Component.h"
#include "SpriteComponent.h"
#include "AnimationComponent.h"
#include "BlockComponent.h"

#include "MoveComponent.h"
#include "InputComponent.h"
#include "CollisionComponent.h"

#include "Boom.h"
#include "Bomb.h"
#include "Player.h"
#include "Block.h"

#include "Tile.h"

#include "Game.h"

#include "Protocol.pb.h"
#include "Enum.pb.h"
#include "Struct.pb.h"