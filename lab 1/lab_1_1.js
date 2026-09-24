'use strict'

function inc(n) {
    return n+1
}
const a = 5
const b = inc(a)
console.dir({a, b});

function inc2(num) {
    num.n++
    return 
}

const obj = { n: 5 }
inc2(obj)
console.dir(obj);