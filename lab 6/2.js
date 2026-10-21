'use strict'

const compose = (...fns) => {
  const f = (x) => {
    try {
      return fns.reduceRight((result, fn) => fn(result), x)
    } catch (e) {
      f.handlers.forEach(handler => handler(e))
      return undefined
    }
  }
  f.handlers = [];

  f.on = (event, handler) => {
    if (event === 'error' && typeof handler === 'function') {
      f.handlers.push(handler)
    }
    return f
  }
  return f
}

const add = x => x + 1
const twice = x => x * 2
const throwError = x => {
  throw new Error('ААААААААААААААААААААААА щось пішло не так')
}

const pipeline = compose(add, twice, throwError)

pipeline.on('error', (e) => {
  console.log('Помилка:', e.message)
})

console.log(pipeline(5))