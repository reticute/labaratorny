'use strict'

function seq(...args) {
    return function next(arg) {
        if (typeof arg === "number") {
            return args.reduce((result, fn) => fn(result), arg)
        }

        return seq(...args, arg)
    }
}

console.log(
    seq(x => x + 7)
        (x => x * 2)(5)
)