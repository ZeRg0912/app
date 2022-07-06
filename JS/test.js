const person = {
    ФИО : {
        И: 'Bob',
        Ф: 'Mayer'
    },
    ВОЗРАСТ: 25
}

const person2 = JSON.parse(JSON.stringify(person))

person2.ФИО.И = 'alice'

function repeat (){
console.log(person2)
console.log(person)
}

repeat()