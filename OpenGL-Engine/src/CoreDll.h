#pragma once
//Engine dll export and import
#ifdef HYDRO_GAME_ENGINE
#define HYDRO_API __declspec(dllexport)
#else
#define HYDRO_API __declspec(dllimport)
#endif