//
// Created by alex on 6/8/15.
//

#include "Game.h"
#include <pong/Paddle.h>


using namespace engine;
using namespace engine::sdl2;

Game::Game()
    : event_handler{new Event_handler},
      screen_w{800},
      screen_h{600}
{
    window = SDL_window::create(800, 600);
    renderer = std::make_unique<SDL_renderer>(SDL_CreateRenderer(window->get(), -1, SDL_RENDERER_ACCELERATED));
    is_running = true;
}

auto Game::Init() -> void
{
    renderer->set_render_color(engine::graphics::Color::black());
    game_objects.push_back(std::make_unique<pong::Paddle>(
            engine::graphics::Rect((screen_w - 150), screen_h / 2, 25, 100)
    ));
}

auto Game::Update() -> void
{
    using namespace engine::graphics;

    while (is_running) {
        renderer->clear(graphics::Color::black());
        event_handler->handle_events();
        if (event_handler->last_event() == EventType::QuitEvent
                || event_handler->last_key_event() == Keycode::Escape) {
            SDL_Quit();
            is_running = false;
        }
        for (auto& object : game_objects) {
            object->do_update(*event_handler);
            object->do_draw(*renderer);
        }
        renderer->present();
    }
}


