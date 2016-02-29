class Card:
    def __init__(self, face, suit):
        self.face = face
        self.suit = suit
        
    def __str__(self):
        return self.face + self.suit

class Order:
    def __init__(self, rank, value):
        self.rank = rank
        self.value = value

    def __lt__(self, other):
        if self.rank == other.rank:
            return self.value < other.value
        else:
            return self.rank < other.rank
    def __eq__(self, other):
        return self.rank == other.rank \
               and self.value == other.value:

FACES = {
    '2': 2, '3': 3, '4': 4, '5': 5, '6': 6,
    '7': 7, '8': 8, '9': 9, 'T': 10, 'J': 11,
    'Q': 12, 'K': 13, 'A': 14 
    }

# 1
def royal_flush(hand):
# 2
def straight_flush(hand):
# 3
def four_of_a_kind(hand):
# 4
def full_house(hand):
# 5
def flush(hand):
# 6
def straight(hand):
# 7
def three_of_a_kind(hand):
# 8
def two_pairs(hand):
# 9
def one_pair(hand):
    all_faces = [FACES[card.face] for card in hand]
    distinct_faces = set(all_faces)
    pairs = [face for face in distinct_faces if all_faces.count(face) == 2]
    if len(pairs) != 1:
        return False
    return Order(9, FACES[pairs[0]])

# 10
def high_card(hand):
    all_faces = [FACES[card.face] for card in hand]
    return Order(10, max(all_faces)) 

hand_rank_order = (royal_flush, straight_flush, \
                   four_of_a_kind, full_house, flush, \
                   straight, three_of_a_kind, two_pairs, \
                   one_pair, high_card)

def rank(hand):
    for ranker in hand_rank_order:
        rank = ranker(hand)
        if rank:
            break
    assert rank, "Invalid: Failed to rank cards: " + hand
    return rank

if __name__ == '__main__':
    with open('poker.txt', 'r') as f:
        for hands in f.readlines():
            hands = hands.split()
            p1_hand = [Card(card[0], card[1]) for card in hands[:5]]
            p2_hand = [Card(card[0], card[1]) for card in hands[5:]]
