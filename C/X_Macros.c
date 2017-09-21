/* XMACRO EXAMPLE */

//					Variable		ADC index
#define X_ADC_CROSSTABLE 	\
		X_XTABLE( 	ADC_CHANNEL1,		1	)	\
		X_XTABLE( 	ADC_CHANNEL2,		3	)	\
		X_XTABLE( 	ADC_CHANNEL3,		4	)	\
		X_XTABLE( 	ADC_CHANNEL4,		2	)	\
		X_XTABLE( 	ADC_CHANNEL5,		0	)	\


/*
Le enum sera composé de :
ADC_CHANNEL1,
ADC_CHANNEL2,
ADC_CHANNEL3,
ADC_CHANNEL4,
ADC_CHANNEL5,
NB_OF_TABLE_ENTRY,  // alors NB_OF_TABLE_ENTRY vaut 5
*/
typedef enum __xTable_e
{
  #define X_XTABLE(VARIABLE, INDEX) VARIABLE,	//Ici on definit que X_TABLE vaut VARIABLE,
    X_ADC_CROSSTABLE							//Le contenu de l'enum, c'est tout les VARIABLE, de la X_ADC_CROSSTABLE une a la suite de l'autre
  #undef X_XTABLE

    NB_OF_TABLE_ENTRY,
} xTable_e;


/*
Cré un tableau dynamiquement selon NB_OF_TABLE_ENTRY et le remplis
Exemple : 
	TonTableau[NB_OF_TABLE_ENTRY] = { 1, 3, 4, 2, 0, };
*/
const uint8_t TonTableau[NB_OF_TABLE_ENTRY] =
{
  #define X_XTABLE(VARIABLE, INDEX) INDEX,
    X_ADC_CROSSTABLE
  #undef X_XTABLE
};