'use strict'

const iterate = (object, callback) => {
  for (const key of Object.keys(object)) {
    callback(key, object[key], object)
  }
}

const obj = { a: 1, b: 2, c: 3 }
iterate(obj, (key, value) => {
  console.log({ key, value })
})
