'use strict'

const removeElements = (array, ...items) => {
  for (const item of items) {
    let index = array.indexOf(item)
    while (index !== -1) {
      array.splice(index, 1)
      index = array.indexOf(item)
    }
  }
}

const array = [1, 2, 3, 4, 5, 6, 7]
removeElements(array, 5, 1, 6)
removeElements(array, 2)
console.log(array)