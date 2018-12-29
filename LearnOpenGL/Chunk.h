#pragma once

#include <vector>

#include "Block.h"
#include "Camera.h"

const int CHUNK_SIZE = 16;

class Chunk
{
public:
	Chunk();
	~Chunk();

	Block blocks[CHUNK_SIZE][CHUNK_SIZE][CHUNK_SIZE];

	void initializeBlocks();
	void generateMesh();
	void render(Camera &cam);

private:

	void tryAddFace(const float face[18], int i, int j, int k, int adj_i, int adj_j, int adj_k);

	std::vector<float> mesh;

	void addToMesh(const float vertices[18], float xOffset, float yOffset, float zOffset);

};
