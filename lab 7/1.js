'use strict'

const removeElement = (array, item) => {
  const index = array.indexOf(item)
  if (index !== -1) {
    array.splice(index, 1)
  }
}


const array = [1, 2, 3, 4, 5, 6, 7]
removeElement(array, 5)
removeElement(array, 7)
console.log(array)