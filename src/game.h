#ifndef GAME_H
#define GAME_H

#include <random>
#include <memory> // For smart pointers
#include <mutex> // For std::mutex
#include "SDL.h"
#include "controller.h"
#include "snake.h"
#include "renderer.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  // Rule of 5
  Game(const Game& other);
  Game(Game&& other) noexcept;
  Game& operator=(const Game& other);
  Game& operator=(Game&& other) noexcept;
  ~Game();

  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  std::unique_ptr<Snake> snake;
  std::unique_ptr<SDL_Point> food;

  // std::random_device is not copyable/movable, so it should not be part of Rule of 5 operations.
  // It's initialized once in the constructor.
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};
  std::mutex score_mutex; // Mutex to protect score updates

  void PlaceFood();
  void Update();
};

#endif

