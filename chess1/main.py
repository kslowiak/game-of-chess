import pygame as p


board = [
    ["R2", "N2", "B2", "Q2", "K2", "B2", "N2", "R2"],
    ["p2", "p2", "p2", "p2", "p2", "p2", "p2", "p2"],
    ["##", "##", "##", "##", "##", "##", "##", "##"],
    ["##", "##", "##", "##", "##", "##", "##", "##"],
    ["##", "##", "##", "##", "##", "##", "##", "##"],
    ["##", "##", "##", "##", "##", "##", "##", "##"],
    ["p1", "p1", "p1", "p1", "p1", "p1", "p1", "p1"],
    ["R1", "N1", "B1", "Q1", "K1", "B1", "N1", "R1"]]

width = height = 512
dim = 8
block = height / dim
FPS = 10
images = {}


def Loadimages():
    pieces = ['p1', 'R1', 'N1', 'B1', 'K1', 'Q1', 'p2', 'R2', 'N2', 'B2', 'K2', 'Q2']
    for piece in pieces:
        images[piece] = p.transform.scale(p.image.load("images/" + piece + ".png"), (block, block))


def main():
    p.init()
    screen = p.display.set_mode((width, height))
    clock = p.time.Clock()
    screen.fill(p.Color("white"))
    Loadimages()
    running = True
    while running:
        for i in p.event.get():
            if i.type == p.QUIT:
                running = False
            clock.tick(FPS)
            p.display.flip()
            drawBoard(screen)
            drawPieces(screen, board)


def drawBoard(screen):
    colors = [p.Color('linen'), p.Color('saddlebrown')]
    for i in range(dim):
        for j in range(dim):
            color = colors[((i + j) % 2)]
            p.draw.rect(screen, color, p.Rect(j * block, i * block, block, block))


def drawPieces(screen, bord):
    for i in range(dim):
        for j in range(dim):
            piece = bord[i][j]
            if piece != "##":
                screen.blit(images[piece], p.Rect(j * block, i * block, block, block))


if __name__ == "__main__":
    main()
