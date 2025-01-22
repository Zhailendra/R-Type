/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Path.hpp
*/

#ifndef RTYPE_PATH_HPP
#define RTYPE_PATH_HPP

#define SPRITE_PATH "assets/"
#define SOUND_PATH "assets/sound/"
/* Backgrounds */

#define BASIC_BACKGROUND_1 SPRITE_PATH "Backgrounds/Background01.png"
#define BASIC_FORGROUND_1 SPRITE_PATH "Backgrounds/Background02.png"
#define BASIC_GROUND_1 SPRITE_PATH "Backgrounds/Background03.png"

#define BLACK_HOLE_PNG SPRITE_PATH "Backgrounds/BlackHole.png"
#define STAR_PNG SPRITE_PATH "Backgrounds/Star.png"
#define BIG_RED_STAR_PNG SPRITE_PATH "Backgrounds/BigRedStar.png"
#define BIG_GREEN_STAR_PNG SPRITE_PATH "Backgrounds/BigGreenStar.png"
#define LITTLE_STAR_PNG SPRITE_PATH "Backgrounds/LittleStar.png"

#define PLANET_PNG SPRITE_PATH "Backgrounds/planet.png"

/* Players */

#define PLAYER_1_SPRITE SPRITE_PATH "players/GreenSpaceShip.png"
#define PLAYER_2_SPRITE SPRITE_PATH "players/BlueSpaceShip.png"
#define PLAYER_3_SPRITE SPRITE_PATH "players/MarineSpaceShip.png"
#define PLAYER_4_SPRITE SPRITE_PATH "players/PurpleSpaceShip.png"
#define PLAYER_5_SPRITE SPRITE_PATH "players/RedSpaceShip.png"


/* Projectiles */

#define PLAYERS_PROJECTILE_SPRITE SPRITE_PATH "projectile/player_projectile.png"
#define FIRE_PROJECTILE_SPRITE SPRITE_PATH "projectile/fire_projectiles.png"
#define ENEMY_PROJECTILE_SPRITE SPRITE_PATH "projectile/enemy_projectile.png"
#define LOADING_LASER_SPRITE SPRITE_PATH "projectile/loading_laser.png"
#define LASER_SPRITE SPRITE_PATH "projectile/laser.png"

#define EXPLOSION_SPRITE SPRITE_PATH "projectile/explosion.png"

/* Enemies */

#define ENEMY_0_SPRITE SPRITE_PATH "enemy/enemy0.png"
#define ENEMY_1_SPRITE SPRITE_PATH "enemy/enemy1.png"
#define ENEMY_2_SPRITE SPRITE_PATH "enemy/enemy2.png"
#define ENEMY_3_SPRITE SPRITE_PATH "enemy/enemy3.png"
#define ENEMY_4_SPRITE SPRITE_PATH "enemy/enemy4.png"
#define ENEMY_5_SPRITE SPRITE_PATH "enemy/enemy5.png"
#define ENEMY_6_SPRITE SPRITE_PATH "enemy/enemy6.png"
#define BOSS_SPRITE SPRITE_PATH "enemy/boss.png"
#define LITTLE_BOSS_SPRITE SPRITE_PATH "enemy/Boss/little_boss.png"
#define LITTLE_BOSS_SHOOTER_SPRITE SPRITE_PATH "enemy/Boss/little_boss_shooter.png"
#define LITTLE_BOSS_PROJECTILE_SPRITE SPRITE_PATH "enemy/Boss/little_boss_projectile.png"

/* Augments */
#define SHIELD_SPRITE_PATH SPRITE_PATH "augments/shield.png"

/* Misc */
#define TOP_LEFT_SPRITE SPRITE_PATH "tile127.png"
#define TOP_MID_SPRITE SPRITE_PATH "tile128.png"
#define TOP_RIGHT_SPRITE SPRITE_PATH "tile129.png"

#define MID_LEFT_SPRITE SPRITE_PATH "tile141.png"
#define MID_MID_SPRITE SPRITE_PATH "tile142.png"
#define MID_RIGHT_SPRITE SPRITE_PATH "tile143.png"

#define BOT_LEFT_SPRITE SPRITE_PATH "tile155.png"
#define BOT_MID_SPRITE SPRITE_PATH "tile156.png"
#define BOT_RIGHT_SPRITE SPRITE_PATH "tile157.png"

#define SPAWNER_BLOCK_SPRITE SPRITE_PATH "spawnerBlock.png"
#define MYSTERY_BLOCK_SPRITE SPRITE_PATH "mysteryBlock.png"
#define ITEM_SPRITE SPRITE_PATH "item.png"

/* SOUND */
#define _MUSIC SOUND_PATH "music.ogg"
#define _LASER_1 SOUND_PATH "laser1.ogg"
#define _LASER_2 SOUND_PATH "laser2.ogg"
#define _DAMAGE SOUND_PATH "damage.ogg"

#include <cstdint>

enum SoundType : std::uint16_t {
    LASER_1 = 0,
    LASER_2,
    MUSIC,
    DAMAGE
};


static const std::map<SoundType, std::string> soundPaths = {
    {LASER_1, _LASER_1},
    {LASER_2, _LASER_2},
    {MUSIC, _MUSIC},
    {DAMAGE, _DAMAGE}
};


enum SpriteType : std::uint16_t {
    BACKGROUND_1 = 0,
    FORGROUND_1,
    GROUND_1,
    BLACK_HOLE,
    STAR,
    BIG_RED_STAR,
    BIG_GREEN_STAR,
    LITTLE_STAR,
    PLANET,
    PLAYER_1,
    PLAYER_2,
    PLAYER_3,
    PLAYER_4,
    PLAYER_5,
    PLAYERS_PROJECTILE,
    ENEMY_PROJECTILE,
    FIRE_PROJECTILE,
    EXPLOSION,
    ENEMY_0,
    ENEMY_1,
    ENEMY_2,
    ENEMY_3,
    ENEMY_4,
    ENEMY_5,
    ENEMY_6,
    BOSS,
    LITTLE_BOSS,
    LITTLE_BOSS_SHOOTER,
    LITTLE_BOSS_PROJECTILE,

    TOP_LEFT,
    TOP_MID,
    TOP_RIGHT,

    MID_LEFT,
    MID_MID,
    MID_RIGHT,

    BOTTOM_LEFT,
    BOTTOM_MID,
    BOTTOM_RIGHT,

    SHIELD_SPRITE,
    LOADING_LASER,
    LASER_PROJECTILE,

    SPAWNER_BLOCK,
    MYSTERY_BLOCK,
    ITEM_LOOTABLE
};

static const std::map<SpriteType, std::string> spritePaths = {
    {BACKGROUND_1, BASIC_BACKGROUND_1},
    {FORGROUND_1, BASIC_FORGROUND_1},
    {GROUND_1, BASIC_GROUND_1},
    {BLACK_HOLE, BLACK_HOLE_PNG},
    {STAR, STAR_PNG},
    {BIG_RED_STAR, BIG_RED_STAR_PNG},
    {BIG_GREEN_STAR, BIG_GREEN_STAR_PNG},
    {LITTLE_STAR, LITTLE_STAR_PNG},
    {PLANET, PLANET_PNG},
    {PLAYER_1, PLAYER_1_SPRITE},
    {PLAYER_2, PLAYER_2_SPRITE},
    {PLAYER_3, PLAYER_3_SPRITE},
    {PLAYER_4, PLAYER_4_SPRITE},
    {PLAYER_5, PLAYER_5_SPRITE},
    {PLAYERS_PROJECTILE, PLAYERS_PROJECTILE_SPRITE},
    {ENEMY_PROJECTILE, ENEMY_PROJECTILE_SPRITE},
    {FIRE_PROJECTILE, FIRE_PROJECTILE_SPRITE},
    {EXPLOSION, EXPLOSION_SPRITE},
    {ENEMY_0, ENEMY_0_SPRITE},
    {ENEMY_1, ENEMY_1_SPRITE},
    {ENEMY_2, ENEMY_2_SPRITE},
    {ENEMY_3, ENEMY_3_SPRITE},
    {ENEMY_4, ENEMY_4_SPRITE},
    {ENEMY_5, ENEMY_5_SPRITE},
    {ENEMY_6, ENEMY_6_SPRITE},
    {BOSS, BOSS_SPRITE},
    {LITTLE_BOSS, LITTLE_BOSS_SPRITE},
    {LITTLE_BOSS_SHOOTER, LITTLE_BOSS_SHOOTER_SPRITE},
    {LITTLE_BOSS_PROJECTILE, LITTLE_BOSS_PROJECTILE_SPRITE},

    {TOP_LEFT, TOP_LEFT_SPRITE},
    {TOP_MID, TOP_MID_SPRITE},
    {TOP_RIGHT, TOP_RIGHT_SPRITE},

    {MID_LEFT, MID_LEFT_SPRITE},
    {MID_MID, MID_MID_SPRITE},
    {MID_RIGHT, MID_RIGHT_SPRITE},

    {BOTTOM_LEFT, BOT_LEFT_SPRITE},
    {BOTTOM_MID, BOT_MID_SPRITE},
    {BOTTOM_RIGHT, BOT_RIGHT_SPRITE},

    {SHIELD_SPRITE, SHIELD_SPRITE_PATH},
    {LOADING_LASER, LOADING_LASER_SPRITE},
    {LASER_PROJECTILE, LASER_SPRITE},

    {SPAWNER_BLOCK, SPAWNER_BLOCK_SPRITE},
    {MYSTERY_BLOCK, MYSTERY_BLOCK_SPRITE},
    {ITEM_LOOTABLE, ITEM_SPRITE}
};

#endif