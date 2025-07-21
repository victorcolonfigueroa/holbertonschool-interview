#!/usr/bin/node
const request = require('request');

/*
    This script prints all characters of a Star Wars movie:
        - The first positional argument passed is the Movie ID - example: 3 = "Return of the Jedi"
        - Display one character name per line in the same order as the "characters" list in the /films/ endpoint
        - You must use the Star Wars API https://swapi-api.hbtn.io/
        - You must use the request module
*/

const movieId = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${movieId}`;

// Helper function to make a request and return a promise
function makeRequest (url) {
  return new Promise((resolve, reject) => {
    request(url, (error, response, body) => {
      if (error) {
        reject(error);
      } else {
        try {
          const data = JSON.parse(body);
          resolve(data);
        } catch (parseError) {
          reject(parseError);
        }
      }
    });
  });
}

// Main execution
request(url, (error, response, body) => {
  if (error) {
    console.error(error);
    return;
  }

  try {
    const data = JSON.parse(body);
    const characters = data.characters;

    // Create an array of promises for character requests
    const characterPromises = characters.map(characterUrl => makeRequest(characterUrl));

    // Wait for all character requests to complete
    Promise.all(characterPromises)
      .then(characterDataArray => {
        // Print character names in the original order
        characterDataArray.forEach(characterData => {
          console.log(characterData.name);
        });
      })
      .catch(error => {
        console.error('Error fetching character data:', error);
      });
  } catch (parseError) {
    console.error('Error parsing movie data:', parseError);
  }
});