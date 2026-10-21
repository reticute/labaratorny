'use strict'

const store = (value) => () => value
const read = store(5)
const value = read()
console.log(value)