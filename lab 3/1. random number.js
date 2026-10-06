'use strict'

function random(min, max) {
    if (max === undefined) {
        max = min;
        min = 0;
    }
     return Math.floor(Math.random() * (max - min + 1)) + min;
}

console.log(random(1, 12))
console.log(random(6))