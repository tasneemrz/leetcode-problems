/**
 * @param {string[]} dictionary
 * @param {string} sentence
 * @return {string}
 */
var replaceWords = function(dictionary, sentence) {
    var words = sentence.split(' ');

    for(let i in words) {
        for(let root of dictionary) {
            let j = 0, k = 0;

            while(j < words[i].length && k < root.length) {
                // if the letters are not equal break
                if(words[i][j] != root[k]) {
                    break;
                }
                j++;
                k++;
            }

            // end of the root word reached 
            // replace the word in words array with the root
            if(k == root.length) {
                words[i] = root;
            }
        }
    }

    return words.join(" ");;
};