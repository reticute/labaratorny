'use strict'

function array() {
    const arr = []

    function access(index) {
        return arr[index]
    }

    access.push = function (value) {
        arr.push(value)
    }

    access.pop = function () {
        return arr.pop()
    }

    return access
}

const arr = array()

arr.push('first')
arr.push('second')
arr.push('third')

console.log(arr(0))
console.log(arr(1))
console.log(arr(2))

console.log(arr.pop())
console.log(arr.pop())
console.log(arr.pop())
console.log(arr.pop())