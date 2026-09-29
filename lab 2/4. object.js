'use strict'

function fn() {
  const obj1 = {name:'Marcus'}
  let obj2 = {name:'Dave'}

 // obj1.name = 'John'
 // obj2.name = 'Jade'

  obj2 = {name: 'Rose'}
  console.log(obj1)
  console.log(obj2)
}
fn();


function createUser(name, city) {
  return { name, city }
}
const user = createUser('Marcus Aurelius', 'Roma')

console.log(user)