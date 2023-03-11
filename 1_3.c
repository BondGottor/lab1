#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(char *s, char *s) {
    size_t len = strlen(s);
    size_t len = strlen(s);
    char *result = malloc(len + len + );
    if (!result) {
        fprintf(stderr, "malloc() failed: insufficient memory!\n");
        return NULL;
    }
    memcpy(result, s, len);
    memcpy(result + len, s, len + );
    return result;
}
char* getfilename(char* path){
    char *filename;
    filename = path + strlen(path);
    for (; filename > path; filename--)
    {
        if ((*filename == '\\') || (*filename == '/'))
        {
            filename++;
            break;
        }
    }
    return filename;
}
int is_letter(char l){
    if((l >= 'A' && l <= 'Z') || (l >= 'a' && l <= 'z')) return ;
    return ;
}
int is_special(char l){	
    if((l >= 'A' && l <= 'Z') || (l >= 'a' && l <= 'z') || (l >= '' && l <= '') || l == ' ' || l == '\n') return ;
    return ;
}
int is_number(char l){
	if(l >= '' && l <= '') return ;
	return ;
}

int main(int argc, char** argv){
    if (argc == ) {
		printf("No arguments\n");
		return ;
	}
	FILE *in;
	FILE *out;
	if(argv[][] == '-' && argv[][] == 'n'){
		if(argc != ) {
			printf("This flag must have  arguments\n");
			return ;
		}
		char* inname = argv[];
		if((in = fopen(inname, "r")) == NULL){
		    printf("File opening failed\n");
		    return ;
		}
		char* outname = argv[];
		if((out = fopen(outname, "w")) == NULL){
		    printf("File opening/creation failed\n");
		    return ;
		}
	}
	else if(argv[][] == '-'){
		if(argc != ) {
			printf("This flag must have  argument\n");
			return ;
		}
		char* inname = argv[];
		if((in = fopen(inname, "r")) == NULL){
		    printf("File opening failed\n");
		    return ;
		}
		char* outname = concat("out_", getfilename(argv[]));
		if((out = fopen(outname, "w")) == NULL){
		    printf("File opening/creation failed\n");
		    return ;
		}
	}
	else{
		printf("Wrong arguments\n");
		return ;
	}
	if ((!strcmp(argv[], "-d")) || (!strcmp(argv[], "-nd"))) {
		char sym;
		while((sym = fgetc(in)) != EOF){
		    if('' <= sym && sym <= '') continue;
		    fputc(sym, out);
		}
	}
	else if ((!strcmp(argv[], "-i")) || (!strcmp(argv[], "-ni"))) {
		int count = ;
		int line = ;
		char sym;
		while((sym = fgetc(in)) != EOF){
			if(is_letter(sym)) count += ;
			else if(sym == '\n'){
				fprintf(out, "Line %d: %d letters\n", line, count);
				count = ;
				line += ;
			}
		}
	}
	else if ((!strcmp(argv[], "-s")) || (!strcmp(argv[], "-ns"))){
		int count = ;
		int line = ;
		char sym;
		while((sym = fgetc(in)) != EOF){
			if(is_special(sym)) count += ;
			else if(sym == '\n'){
				fprintf(out, "Line %d: %d special symbols\n", line, count);
				count = ;
				line += ;
			}
		}
	}
	else if ((!strcmp(argv[], "-a")) || (!strcmp(argv[], "-na"))){
		char sym;
		int asci;
		while((sym = fgetc(in)) != EOF){
			if(!is_number(sym)){
				asci = sym;
				fprintf(out, "%d", asci);
			}
			else fputc(sym, out);
		}
	}
	else if ((!strcmp(argv[], "-f")) || (!strcmp(argv[], "-nf"))){
		char sym;
		int asci;
		int lecsemcnt = ;
		int is_skip = ;
		while((sym = fgetc(in)) != EOF){
			if(sym == ' ' || sym == '\t' || sym == '\v' || sym == '\n'){
				if(!is_skip){
					lecsemcnt++;
					is_skip = ;
				}
				fputc(sym, out);
			}
			else{
				is_skip = ;
				if((lecsemcnt %  == ) && (sym >= 'A' && sym <= 'Z')) sym += ;
				if(lecsemcnt %  == ){
					asci = (int)sym;
					fprintf(out, "%d", asci);
				}
				else fputc(sym, out);
			}
		}
	}
	else {
		printf("Wrong argument(s)\n");
		return ;
	}
	fclose(in);
	fclose(out);
    return ;
}
