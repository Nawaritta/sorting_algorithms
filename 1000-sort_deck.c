#include "deck.h"
/**
 * swap_cards - swaps two cards from a deck of cards.
 * @deck: a doubly linked list representing the cards deck
 * @card_1: the node on the left
 * @card_2: the node on the right
 */
void swap_cards(deck_node_t **deck, deck_node_t *card_1, deck_node_t *card_2)
{
	if (card_1->prev)
		card_1->prev->next = card_2;
	else
		*deck = card_2;
	if (card_2->next)
		card_2->next->prev = card_1;
	card_2->prev = card_1->prev;
	card_1->next = card_2->next;
	card_2->next = card_1;
	card_1->prev = card_2;
}

/**
 * dummyVal - assignes a dummy values to the cards to help sorting the cards
 *             We choose to add:
 *             => Nothing to Spade cards, Spade range is [1 - 13]
 *             =>  20 to Heart cards, Heart range is [21 - 33]
 *             =>  40 to Club cards, Club range is [41 - 43]
 *             =>  60 to Diamond cards, Diamond range is [61 - 73]
 *
 *@node: The card to check
 *
 *Return: an integer from 1 to 73
 */
int dummyVal(deck_node_t *node)
{
	int value, dummy;

	if (strcmp(node->card->value, "King") == 0)
	{
		value = 13;
	} else if (strcmp(node->card->value, "Queen") == 0)
	{
		value = 12;
	} else if (strcmp(node->card->value, "Jack") == 0)
	{
		value = 11;
	} else
		value = atoi(node->card->value);

	switch (node->card->kind)
	{
	case SPADE:
		dummy = value;
		break;
	case HEART:
		dummy = value + 20;
		break;
	case CLUB:
		dummy = value + 40;
		break;
	case DIAMOND:
		dummy = value + 60;
		break;
	default:
		dummy = value;
		break;
	}
	return (dummy);
}
/**
 * sort_deck - sorts a deck of cards From Ace to King - From Spades to Diamonds
 * @deck: double pointer to the deck of cart to be sorted
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *cursor = NULL;
	int range = 52, index;

	cursor = *deck;
	while (range > 1)
	{
		index = 0;
		range--;
		while (cursor->next && index < range)
		{
			if (dummyVal(cursor) > dummyVal(cursor->next))
			{
				swap_cards(deck, cursor, cursor->next);
				cursor = cursor->prev;
			}
			else
				cursor = cursor->next;
			index++;
		}
		index = 0;
		while (cursor->prev && index < range)
		{
			if (dummyVal(cursor) < dummyVal(cursor->prev))
			{
				swap_cards(deck, cursor->prev, cursor);
				cursor = cursor->next;
			}
			else
				cursor = cursor->prev;
			index++;
		}
	}

}
