#pragma once

using ActionRef = std::shared_ptr<class Action>;
using PacketRef = std::shared_ptr<class Packet>;
using ClientEngineRef = shared_ptr<class ClientEngine>;
using ServerSessionRef = shared_ptr<class ServerSession>;
using ComponentRef = shared_ptr<class Component>;
using SpriteComponentRef = shared_ptr<class SpriteComponent>;
using CollisionComponentRef = shared_ptr<class CollisionComponent>;
using AnimationComponentRef = shared_ptr<class AnimationComponent>;
using BlockComponentRef = shared_ptr<class BlockComponent>;
using ActorRef = shared_ptr<class Actor>;
using PlayerRef = shared_ptr<class Player>;
using ItemRef = shared_ptr<class Item>;
using BombRef = shared_ptr<class Bomb>;
using BoomRef = shared_ptr<class Boom>;
using TileRef = shared_ptr<class Tile>;
