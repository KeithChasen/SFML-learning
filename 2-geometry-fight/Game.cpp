#include "Game.h"

#include <iostream>

Game::Game(const std::string & config)
{
    init(config);
}

void Game::init(const std::string & path)
{
    // TODO: read config here
    // use PlayerConfig, EnemyConfig, BulletConfig


    // std::ifstream fin(path);

    // fin >> m_playerConfig.SR >> m_playerConfig.CR;

    // set up window parameters
    m_window.create(sf::VideoMode(1280, 720), "Geometry Fight");
    m_window.setFramerateLimit(60);

    spawnBullet();    
}

void Game::run()
{
    // todo: add pause functionality
    // rendering SHOULD function
    // movement / input SHOULDN'T

    while (m_running)
    {
        m_entities.update();

        sEnemySpawner();
        sMovement();
        sCollision();
        sUserInput();
        sRender();

        // increment current frame
        m_currentFrame++;
    }
}

void Game::setPaused(bool paused)
{
    // todo
}

void Game::spawnPlayer()
{
    // todo: finish adding all properties
    // of the player with values from config

    // we create every entity by calling EntityManager.addEntity(tag)
    // this returns a std::shared_ptr<Entity> so we use auto to save typing
    auto entity = m_entities.addEntity("player");

    //  entity spawns in the middle
    float mx = m_window.getSize().x / 2.0f;
    float my = m_window.getSize().y / 2.0f;

    //  give this entity a Transform so it spawns at 200, 200 with velocity 1,1
    // and angle 0
    entity->cTransform = std::make_shared<CTransform>(
        Vec2(mx, my), 
        Vec2(1.0f, 1.0f),
        0.0f
    );

    // the entity's shape will have radius 32, 
    // 8 sides, dark grey fill and red outline of thickness 4
    entity->cShape = std::make_shared<CShape>(
        32.0f,
        8,
        sf::Color(10, 10, 10),
        sf::Color(255, 0, 0),
        4.0f
    );

    //add an input component to the player so that we can use inputs
    entity->cInput = std::make_shared<CInput>();

    // Since we want this entity to be our player
    // set our Game's player variable to be this entity
    // this goes slightly against EntityManager paradigm
    // but we use the player so much it's worth it
    m_player = entity;
}

void Game::spawnEnemy()
{
    // todo: make sure enemy spawned properly with m_enemyConfig
    // the enemy should spawn completely within the bounds of the window

    auto entity = m_entities.addEntity("enemy");

    // give this entity a Transform 
    // so it spawns at (random, random) with velocity (0,0) and angle 0
    float ex = rand() % m_window.getSize().x;
    float ey = rand() % m_window.getSize().y;

    entity->cTransform = std::make_shared<CTransform>(Vec2(ex, ey), Vec2(0,0f, 0,0f), 0.0f);

    entity->cShape = std::make_shared<CShape>(
        16.0f, 3, 
        sf::Color(0,0,255),
        sf::Color(255,255,255),
        4.0f
    );

    // record when the most recent enemy was spawned
    m_lastEnemySpawnTime = m_currentFrame;
}

void Game::sRender()
{
    // todo: draw all the entities

    m_window.clear();

    for (auto e : m_entities.getEntities()) 
    {
        // set position of shape based on the entity's transform->pos
        e->cShape->circle.setPosition(
            e->cTransform->pos.x,
            e->cTransform->pos.y
        );

        // set the rotation of the shape based on transform->angle
        e->cTransform->angle += 1.0f;
        e->cShape->circle.setRotation(e->cTransform->angle);

        // draw the entity's sf::CircleShape
        m_window.draw(e->cShape->circle);
    }

    m_window.display();
}