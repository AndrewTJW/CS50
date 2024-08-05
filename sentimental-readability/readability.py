def get_text():
    text = input("Text: ")
    return text

def coleman_algo(text):
    #count number of letter
    letter_count = 0
    word_count = 0
    for letter in (text):
        if letter.isalpha() == True:
            letter_count += 1
    for word in (text):
        if word == " ":
            word_count += 1
    word_count = word_count + 1
    #count number of letter per 100 words
    nolphw = (letter_count / word_count) * 100
    #count number of sentences
    number_of_sentences = 0
    for character in text:
        if character == "." or character == "?" or character == "!":
            number_of_sentences += 1
    #average number of sentence per 100 word
    anosph = (number_of_sentences / word_count) * 100

    #algorithm
    grade = int(round((0.0588 * nolphw) - (0.296 * anosph) - 15.8))
    return grade

def grade_indentification(grade):
    if grade >= 16:
        print("Grade 16+")
    elif grade <= 1:
        print("Before Grade 1")
    else:
        print(f'Grade {grade}')


in_text = get_text()
grade = coleman_algo(in_text)
grade_indentification(grade)
