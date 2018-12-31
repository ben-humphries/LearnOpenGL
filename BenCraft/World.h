#pragma once

#include "Chunk.h"
#include "Camera.h"
#include "PerlinNoise.hpp"

#include <thread>
#include <mutex>


const int MAX_CHUNKS = 128;
const int SQRT_MAX_CHUNKS = glm::sqrt(MAX_CHUNKS);

class World
{
public:
	World(Camera * cam);
	~World();

	std::vector<Chunk> chunks;

	void render(Camera & cam);


private:
	long worldSizeBlocks;

	void updateChunks(Camera * cam);
	void startUpdatingChunks(Camera * cam);

	int getHeightAtXZ(glm::vec2 position);

	int getChunkAt(glm::vec3 position);

	void loadChunk(glm::vec3 position);
	bool isChunkLoaded(glm::vec3 position);
	bool isChunkLoaded(int index);
	void unloadChunk(glm::vec3 position);
	void unloadChunk(int index);

	std::map<float, int> sortChunksByDistanceToCamera(Camera & cam);

	std::thread update_chunks_thread;
	std::mutex mutex;
};

