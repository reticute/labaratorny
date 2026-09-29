'use strict'

function range(start, end) {
    let result = []

    for (let i = start; i <= end; i++) {
    result.push(i)
  }
 return result
}

console.log(range(15, 30))


function rangeOdd(start, end) {
    let resultOdd = []
    for (let i = start; i <= end; i++) {
    if (i % 2 !== 0) {
      resultOdd.push(i);
        }
    }
    return resultOdd
}

console.log(rangeOdd(15, 30))
