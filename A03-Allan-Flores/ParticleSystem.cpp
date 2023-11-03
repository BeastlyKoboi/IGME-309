#include <GL/glew.h>
#include <GL/freeglut.h>
#include "ParticleSystem.h"
#include <iostream>

ParticleSystem::ParticleSystem(int _numParticles)
{
	numParticles = _numParticles;	// Set the number of particles
	
	// Allocate memory for positions, velocities, colors, and lifetimes.
	positions = new float[numParticles * 3];
	velocities = new float[numParticles * 3];
	colors = new float[numParticles * 4];	
	lifeTimes = new float[numParticles];

	for (int i = 0; i < numParticles; i++) {
		// Initialize the life times
		lifeTimes[i] = maxLifeTime - maxLifeTime * i / numParticles;

		/***************************/
		// Write your code below
		// Please add initializations for other arrays as you see appropriate.
		
		// Position Initializations
		positions[i * 3 + 0] = 0;
		positions[i * 3 + 1] = 0;
		positions[i * 3 + 2] = 0;

		// Velocity Initializations
		velocities[i * 3 + 0] = getRandomValue(minSpeedX, maxSpeedX);
		velocities[i * 3 + 1] = getRandomValue(minSpeedY, maxSpeedY);
		velocities[i * 3 + 2] = getRandomValue(minSpeedZ, maxSpeedZ);

		// Red color Initialization
		colors[i * 4 + 0] = 1.0f;
		colors[i * 4 + 1] = 0.0f;
		colors[i * 4 + 2] = 0.0f;
		colors[i * 4 + 3] = 1.0f;

		/***************************/
	}
}

void ParticleSystem::update(float deltaTime)
{
	for (int i = 0; i < numParticles; i++) {
		/***************************/
		// Write your code below
		// Update lifetime, velocity, position, and color.
		// Reset particle states (positions, velocities, colors, and lifetimes) when the lifetime reaches the maxLifeTime
		lifeTimes[i] += deltaTime;

		if (lifeTimes[i] > maxLifeTime)
		{
			// Position Initializations
			positions[i * 3 + 0] = 0;
			positions[i * 3 + 1] = 0;
			positions[i * 3 + 2] = 0;

			// Velocity Initializations
			velocities[i * 3 + 0] = getRandomValue(minSpeedX, maxSpeedX);
			velocities[i * 3 + 1] = getRandomValue(minSpeedY, maxSpeedY);
			velocities[i * 3 + 2] = getRandomValue(minSpeedZ, maxSpeedZ);

			// Reset Lifetime
			lifeTimes[i] = 0;

			continue;
		}

		// Update positions and velocity 
		positions[i * 3 + 0] += velocities[i * 3 + 0] * deltaTime;
		positions[i * 3 + 1] += velocities[i * 3 + 1] * deltaTime;
		positions[i * 3 + 2] += velocities[i * 3 + 2] * deltaTime;

		velocities[i * 3 + 1] += acceleration[1] * deltaTime;

		// Decrease Alpha color channel as time goes on	
		colors[i * 4 + 3] = 1 - lifeTimes[i] / maxLifeTime;
		
		// Write your code above
		/***************************/
	}
}

void ParticleSystem::draw()
{
	/***************************/
	// Write your code below
	// Use GL_POINTS for rendering
	
	glPointSize(3.0f);
	glBegin(GL_POINTS);

	for (int i = 0; i < numParticles; i++) {
		glColor4f(colors[i * 4 + 0], colors[i * 4 + 1], colors[i * 4 + 2], colors[i * 4 + 3]);

		glVertex3f(positions[i * 3 + 0], positions[i * 3 + 1], positions[i * 3 + 2]);
	}

	glEnd();

	// Write your code above
	/***************************/
}

float ParticleSystem::getRandomValue(float min_value, float max_value)
{
	return min_value + (std::rand()) / (RAND_MAX / (max_value - min_value));;
}
