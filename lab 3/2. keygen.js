'use strict';

const characters = 'abcdefghijklmnopqrstuvwxyz0123456789'
const key = keygen(16, characters)

function keygen(length, characters) {
  let key = '';
  const charsLength = characters.length; 
  for (let i = 0; i < length; i++) { 
    const randomIndex = Math.floor(Math.random() * charsLength);
    key += characters[randomIndex];
  }

  return key;
}

console.log(key)