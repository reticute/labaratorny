'use strict'

function average(a, b) {
  return (a + b) / 2;
}

function square(x){
  return x*x;
}

function cube(x){
  return x*x*x;
}


function calculate() {
  let result = []
  for (let i = 0; i <= 9; i++) {
    let sq = square(i);
    let cb = cube(i);
    let avg = average(sq, cb);
    result.push(avg);
  }
  
  return result;
}

console.log(calculate())