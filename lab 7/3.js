'use strict'

const unique = (array) => {
  return [...new Set(array)]
}

const result = unique([2, 1, 1, 3, 2, 4, 7, 7])
const result2 = unique(['top', 'bottom', 'top', 'left'])
console.log(result, result2)
