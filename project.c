#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void incrementG(int choice, int *, int *, int *, int*);
void incrementF(int choice, int *, int *, int *, int *);
void incrementC(int choice, int *, int *, int *, int *);
int keepGoing(int x);
int analyze(int *, int *, int *, int *, char *, char *, char *);

int main(void)
{
int cont = 1;
while(cont == 1)
{
int x;
int *lh; int lh1 = 0; lh = &lh1;
int *fun; int fun1 = 0; fun = &fun1; 
int serious1 = 0; int *serious; serious = &serious1;
int feels1 = 0; int *feels; feels = &feels1;
int fchoice;
int score;
int tchoice;
char rating[15];
int gchoice;
int cchoice;
char character[20];
char format[20];
char genre[15];
char *genres[10] = {"Action", "Comedy", "Drama", "Historical", "Scientific","Political", "Music", "Food", "Tech"};
char *formats[11] = {"Vlog", "Talk_Show", "Real_World", "Reaction", "Music_Video", "Documentary", "Movie_Trailer", "Video_Editorial", "Explanation", "Unboxing"};
char *characters[8] = {"Celebrities", "Millenials", "Kids", "Artists", "Personalities", "Normal_Folk", "Expert"};

	printf("=======================================\nWELCOME TO THE YOUTUBE SUCCESS PREDICTOR\n=======================================\n");
	printf("Note: The data used to build this was taken from Youtube Popular, so this only applies to that section of youtube.  Try out combinations that make sense, but many unorthadox combinations will land you a good video as well!\n\n");
	
	printf("======GENRES======\n\n");
	for(x = 0; x < 9; x++)
	{
		printf("%d.", x + 1);
		printf(" %s\n", genres[x]);
		
	}
	printf("Please select a genre! (enter the corresponding number): ");
	scanf("%d", &gchoice);
	strcpy(genre, genres[gchoice - 1]);
	incrementG(gchoice, lh, fun, serious, feels);
	printf("\n\n ======FORMATS======\n\n");
	for(x = 0; x < 10; x++)
	{
		printf("%d.", x + 1);
		printf(" %s\n", formats[x]);
	}
	printf("Now please select which format you'd like (enter the corresponding number): ");
	scanf("%d", &fchoice);
	strcpy(format, formats[fchoice -1]);
	incrementF(fchoice, lh, fun, serious, feels);
	printf("\n\n========CHARACTERS========\n\n");
	for(x = 0; x < 7; x++)
	{
		printf("%d.", x + 1);
		printf(" %s\n", characters[x]);
	}
	printf("Now select what sort of characters you wish to appear in your video (enter the corresponding number): ");
	scanf("%d", &cchoice);
	strcpy(character, characters[cchoice - 1]);
	incrementC(cchoice, lh, fun, serious, feels);
	printf("\n\n=======ANALYSIS=======");
	score = analyze(lh, fun, serious, feels, character, format, genre);
	if(strcmp(genre, "Political") == 0)
	{
		printf("Is your political video about Trump? (1 for yes, 0 for no): ");
		scanf("%d", &tchoice);
		while(tchoice < 0 && tchoice > 1)
		{
			printf("Is it really that hard to enter 1 or 0?: ");
			scanf("%d", &tchoice);
		}
		switch(tchoice)
		{
		case 1:
			score+= 5;
			break;
		case 2:
			score-= 5;
			break;
		}
	}
	printf("========================================\n");
	if(score <= 0)
	{
		strcpy(rating, "Awful");
	}
	if(score > 0 && score < 3)
	{
		strcpy(rating, "Eh");
	}
	if(score > 3 && score < 7)
	{
		strcpy(rating, "Average");
	} 
	if(score > 7 && score < 11)
	{
		strcpy(rating, "Good");
	}
	if(score > 10)
	{
		strcpy(rating, "Excellent");
	}
	printf("\n\n=========================KEY=================================\n");
	printf("Awful = Try again pal\n");
	printf("Eh = Not horrible but will never make it\n");
	printf("Average = You've got a chance, but not a good one\n"); 
	printf("Good = There's a good chance you'll be on youtube popular\n");
	printf("Excellent = Get ready to rake in the views and admiration of children\n");
	printf("=================================================================\n\n\n");
	printf("===================================RATING==========================================\n");
	printf("Your video that has format %s that is mainly %s and stars %s is %s\n", format, genre, character, rating);
	printf("===================================================================================\n");
	printf("\nWould you like to test another video idea?(Enter 1 for yes, 0 for no): ");
	
	scanf("%d", &cont);
}

}
void incrementF(int choice, int *lh, int *fun, int *serious, int *feels)
{
	switch(choice)
	{
	case 1://Vlog
	(*fun) += 2;
	break;
	case 2://Talk Show
	(*fun)++;
	(*lh)++;
	break;
	case 3://Real World
	(*serious)++;
	(*feels)++;
	(*fun)++;
	break;
	case 4://Reaction
	(*fun) += 2;
	(*feels)++;
	break;
	case 5:// Music Vid
	(*fun)++;
	(*feels) += 2; 
	break;
	case 6://Documentary
	(*serious) += 2;
	break;
	case 7://Movie Trailer
	(*fun) += 2;
	(*serious)++;
	break;
	case 8://Video editorial
	(*serious)++;
	break;
	case 9://Explanation
	(*serious) += 2;
	break;
	case 10://Unboxing
	(*fun)++;
	(*lh)++;
	(serious)++;
	break;
	}
}
void incrementG(int choice, int *lh, int *fun, int *serious, int *feels)
{
	switch(choice)
	{
	case 1://Action
	(*fun)++;
	break;
	case 2://Comedy
	(*fun) += 2;
	(*lh)++;
	break;
	case 3://Drama
	(*serious)++;
	(*feels) += 2;
	break;
	case 4://Historical
	(*serious)++;
	break;
	case 5://Scientific
	(*serious) += 2;
	break;
	case 6://Political
	(*serious) += 2;
	break;
	case 7://Music
	(*lh) += 2;
	(*fun)++;
	(*feels)++;
	break;
	case 8://Food
	(*fun)++;
	(*lh) += 2;
	break;
	case 9://Tech
	(*serious)++;
	(*fun)++;
	
	}
}
void incrementC(int choice, int *lh, int *fun, int *serious, int *feels)
{
	switch(choice)
	{
	case 1://Celebs
	(*fun) += 3;
	(*lh)++;
	break;
	case 2://Millenials
	(*fun) += 2;
	(*lh)++;
	break;
	case 3://Kids
	(*lh) += 4;
	(*feels) += 2;
	(*fun)++;
	break;
	case 4://Artists
	(*fun) += 2;
	(*feels) += 2;
	break;
	case 5://Personalities
	(*fun)++;
	(*lh) += 2;
	break;
	case 6://Normal Folk
	(*feels) += 2;
	(*lh)++;
	break;
	case 7://Experts
	(*serious) += 3;
	break;
	
	}
}
int analyze(int *lh, int *fun, int *serious, int *feels, char* character, char* format, char* genre)
{
	int rating = 0;
	printf("\n***If nothing appears here your score is still totaled but I dont have any quips for what you selected***\n\n");
	if((*lh) >= 5)
	{
		printf("Your video is very light-hearted, which goes over well on youtube popular.\n");
		rating += 5;
	}
	if((*fun) >= 5)
	{
		printf("Your video is very fun, which is what you primarily see on youtube popular.\n");
		rating += 6;
	}
	if((*serious) >= 5)
	{
		printf("Your video is very serious, which does alright on youtube popular.\n");
		rating += 4;
	}
	if((*feels) >= 5)
	{
		printf("Your video tugs at the heart strings, which doesn't seem to do great on youtube popular.\n");
		rating += 2;
	}
	if (strcmp(format, "Music_Video") == 0)
	{
		printf("Good call doing a music video.  This was by far the largest sort of video appearing on popular.\n");
		rating += 4;	
	}
	if (strcmp(format, "Movie_Trailer") == 0)
	{
		printf("Trailer was a good choice.  These absolutely rake in the views.\n");
		rating += 4;
	}
	if (strcmp(genre, "Scientific") == 0)
	{
		printf("Your mostly appealing to the younger generations stupid science bitch, kids don't want to learn!\n");
		rating -= 4;
	}
	if (strcmp(character, "Celebrities") == 0)
	{
		printf("Everyone wants to see their favorite celeb doing some dumb thing or another.  Good call.\n");
		rating += 2;
	}
	if (strcmp(character, "Celebrities") == 0 && strcmp(format, "Talk_Show") == 0)
	{
		printf("You chose celebs and talk show, What are you Jimmy Kimmel? Well he kills it on youtube.  Good call.\n");
		rating += 4;
	}
	if (strcmp(character, "Millenials") == 0 && strcmp(format, "Vlog") == 0)
	{
		printf("A millenial vlogger eh.  While they are widely hated the kids eat it up.  Good call. \n");
		rating += 4;
	}
	if(strcmp(genre, "Music") == 0 && strcmp(format, "Music_Video") == 0)
	{
		printf("A music video huh, these are all over youtube popular, good choice\n");
		rating += 4;
	}
	if(strcmp(genre, "Tech") == 0 && strcmp(format, "Unboxing") == 0)
	{
		printf("Tech unboxing is popular on youtube, but not so much on youtube popular\n");
		rating += 4;
	}
	if(strcmp(character, "Millenials") == 0)
	{
		printf("Millenials are all the rage. Good work.\n");
		rating += 4;
	}
	if(strcmp(genre, "Action") == 0 && strcmp(format, "Real_World") == 0)
	{
		printf("While videos of people doing things on the streets don't dominate youtube popular, they tend to garner a lot of views when they do.\n");
		rating += 3;
	}
	if(strcmp(genre, "Comedy") == 0)
	{
		printf("Comedy is the dominating genre on youtube popular.\n");
		rating += 4;
	}
	if(strcmp(genre, "Historical") == 0)
	{
		printf("Not many history videos on popular, not the best call.\n");
		rating -= 2;
	}
	if(strcmp(genre, "Political") == 0)
	{
		printf("Politics bores people.  Unless its about Trump. So your rating stays unaffected\n");
		
	}
	if(strcmp(genre, "Drama") == 0)
	{
		printf("Everyone loves some juicy gossip\n");
		rating+= 4;
	}
	if(strcmp(genre, "Music") == 0)
	{
		printf("Music is all over youtube popular.\n");
		rating+= 4;
	}
	if(strcmp(genre, "Food") == 0)
	{
		printf("Did you know the Food Network's rating skyrocketed after 9/11? Everyone needs some comfort right now, food was a good call.\n");
		rating+= 3;
	}
	if (strcmp(genre, "Tech") == 0)
	{
		printf("Tech does alright on youtube popular.\n");
		rating+= 2;
	}
	if(strcmp(format, "Vlog") == 0)
	{
		printf("For some reason people really enjoy vlogs even though most feel like one big intro.\n");
		rating+= 3;
	}
	if(strcmp(genre, "Comedy") == 0 && strcmp(format, "Reaction") == 0 && strcmp(character, "Kids") == 0)
	{
		printf("Congratulations, you are the fine brothers.  They always have a video on youtube popular.\n");
		rating+=5;
	}
	if(strcmp(genre, "Action") == 0)
	{
		printf("Action does alright on youtube popular\n");
		rating+=2;	
	}
	if(strcmp(genre, "Drama") == 0 && strcmp(format, "Real_World") == 0)
	{
		printf("Going for the reality route eh, works better on MTV\n");
		rating+=3;	
	}
	if(strcmp(character, "Kids") == 0)
	{
		printf("Whether they are doing something dumb or being forced by their parents to be a in a youtube video, kids do well on youtube popular.\n");
		rating += 3;	
	}	
	return rating;
}

