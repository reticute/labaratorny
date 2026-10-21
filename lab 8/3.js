'use strict'

const contract = (fn, ...types) => (...args) => {
  for (let i = 0; i < args.length; i++) {
    const expectedType = types[i]
    if (typeof args[i] !== expectedType.name.toLowerCase()) {
      throw new TypeError(`Невалідний аргумент ня позиції ${i}`)
    }
  }
  const result = fn(...args)
  const resultType = types[types.length - 1]
  if (typeof result !== resultType.name.toLowerCase()) {
    throw new TypeError('Невідповідний тип результату')
  }
  return result
}


const add = (a, b) => a + b
const addNumbers = contract(add, Number, Number, Number)
const res1 = addNumbers(2, 3)
console.dir(res1) 

const concat = (s1, s2) => s1 + s2
const concatStrings = contract(concat, String, String, String)
const res2 = concatStrings('Hello ', 'world!')
console.dir(res2)


/* змодифіковані приклади для перевірки помилок :

const add = (a, b) => a + b
const addNumbers = contract(add, Number, Number, Number)
const res1 = addNumbers("Hi", 3)
console.dir(res1)

const concat = (a, b) => String(a + b)
const typesError = contract(concat, Number, Number, Number)
typesError(2, 3)
*/
