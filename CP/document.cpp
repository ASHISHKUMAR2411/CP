char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) {
    return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];
}

char** split_string(char* text, char delim) {
    assert(text != NULL);
    char** result = malloc(1*sizeof(char*));
    int size = 1;
    
    char* temp = strtok(text, &delim);
    *result = temp;
    
    while(temp != NULL) {
        size++;
        result = realloc(result,size*sizeof(char*));
        temp = strtok(NULL, &delim);
        result[size-1] = temp;
    }
    return result;
}

char**** get_document(char* text) {
    assert(text != NULL);
    
    // split text by '\n' and count number of paragraphs
    char** paragraphs = split_string(text, '\n');
    int npar = 0;
    while (paragraphs[npar] != NULL) {
        npar++;
    }
    
    char**** doc = malloc((npar+1)*sizeof(char***));
    // set last position to NULL for the user
    // to know when the array ends.
    doc[npar] = NULL; 
    
    int i = 0;
    while (paragraphs[i] != NULL) {
        
        // split sentences of paragraph by '.' and count number of sentences
        char** sentences = split_string(paragraphs[i], '.');
        int nsen = 0;
        while(sentences[nsen] != NULL) {
            nsen++;
        }
        
        doc[i] = malloc((nsen+1)*sizeof(char**));
        // set last position to NULL for the user
        // to know when the array ends.
        doc[i][nsen] = NULL; 
        
        int j = 0;
        while (sentences[j] != NULL) {
            
            // remember that doc[0][0] means: paragraph #0,
            // sentence #0 and should act like a pointer to
            // the first element of an array of words (strings)
            
            // split string by ' ' and associate doc[i][j]
            // with the array of strings representing words
            // that is returned by split_string.
            doc[i][j] = split_string(sentences[j], ' ');
            j++;
        }
        i++;
    }
    
    return doc; 
}
 char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
            return document[n - 1][m - 1][k - 1];
    }

    char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) {
            return document[m - 1][k - 1];
    }

    char*** kth_paragraph(char**** document, int k) {
            return document[k - 1];
    }

    char**** get_document(char* str) {
            char**** doc = malloc(MAX_PARAGRAPHS * sizeof(char***));

            for (int p = 0; p < MAX_PARAGRAPHS; p++) {
                    *(doc + p) = malloc(MAX_SENTENCES * sizeof(char**));

                    for (int s = 0; s < MAX_SENTENCES; s++) {
                            *(*(doc + p) + s) = malloc(MAX_WORDS * sizeof(char*));

                            for (int w = 0; w < MAX_WORDS; w++) {
                                    *(*(*(doc + p) + s) + w) = malloc(MAX_CHARACTERS * sizeof(char));
                            }
                    }
            }

            char para[25][3125];
            char sent[625][625];

            int s_to_p[625];

            int p_ptr = 0;
            char *p = strtok(str, "\n");
            while (p != NULL) {
                    if (strlen(p) != 0) {
                            strcpy(para[p_ptr], p);
                            p_ptr++;
                    }
                    p = strtok(NULL, "\n");
            }

            int s_ptr = 0;
            for (int p_itr = 0; p_itr < p_ptr; p_itr++) {
                    char *s = strtok(para[p_itr], ".");

                    while (s != NULL) {
                            if (strlen(s) != 0) {
                                    strcpy(sent[s_ptr], s);
                                    s_to_p[s_ptr] = p_itr;
                                    s_ptr++;
                            }

                            s = strtok(NULL, ".");
                    }
            }

            int temp = 0;
            for (int s_itr = 0; s_itr < s_ptr; s_itr++) {
                    int w_ptr = 0;
                    char *w = strtok(sent[s_itr], " ");

                    if (s_itr > 0 && (s_to_p[s_itr] != s_to_p[s_itr - 1])) {
                            temp = 0;
                    }

                    while(w != NULL) {
                            if (strlen(w) != 0) {
                                    strcpy(doc[s_to_p[s_itr]][temp][w_ptr], w);
                                    w_ptr++;
                            }

                            w = strtok(NULL, " ");
                    }

                    temp++;
            }


            return doc;
    }

