#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <future> // For std::async
#include "controller.h"
#include "game.h"
#include "renderer.h"

struct HighScore {
    std::string name;
    int score;

    bool operator<(const HighScore& other) const {
        return score > other.score;
    }
};

void saveHighScores(const std::vector<HighScore>& scores, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& hs : scores) {
            file << hs.name << " " << hs.score << "\n";
        }
        file.close();
    } else {
        std::cerr << "Unable to open file for saving high scores.\n";
    }
}

std::vector<HighScore> loadHighScores(const std::string& filename) {
    std::vector<HighScore> scores;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string name;
        int score;
        while (file >> name >> score) {
            scores.push_back({name, score});
        }
        file.close();
    } else {
        std::cerr << "Unable to open file for loading high scores. Creating new file.\n";
    }
    return scores;
}

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";

  std::cout << "Enter your name for the high score: ";
  std::string playerName;
  std::cin >> playerName;

  // Use std::async for loading high scores
  std::future<std::vector<HighScore>> load_future = std::async(std::launch::async, loadHighScores, "highscores.txt");
  std::vector<HighScore> highScores = load_future.get();

  highScores.push_back({playerName, game.GetScore()});
  std::sort(highScores.begin(), highScores.end());

  // Keep only top 10 scores
  if (highScores.size() > 10) {
      highScores.resize(10);
  }

  // Use std::async for saving high scores
  std::async(std::launch::async, saveHighScores, highScores, "highscores.txt");

  std::cout << "\n--- High Scores ---\n";
  for (const auto& hs : highScores) {
      std::cout << hs.name << ": " << hs.score << "\n";
  }

  return 0;
}

