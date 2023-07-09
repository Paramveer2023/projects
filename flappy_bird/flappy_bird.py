import pygame
from pygame.locals import *
import random  # to bring randomness in game
import sys  # to exit out of game using sys.exit

# global variabes for the game
FPS = 32
SCREENWIDTH = 289
SCREENHEIGHT = 511

screen = pygame.display.set_mode((SCREENWIDTH, SCREENHEIGHT))
groundy = SCREENHEIGHT * 0.8
sprites = {}
sound = {}
background = 'gallery/sprites/background.png'
player = 'gallery/sprites/bird.png'
pipe = 'gallery/sprites/pipe.png'


def welcomescreen():
    playerx = int(SCREENWIDTH / 5)
    playery = int((SCREENHEIGHT - sprites['player'].get_height())/2)
    messagex = int((SCREENWIDTH - sprites['message'].get_width())/2)
    messagey = int(SCREENHEIGHT*0.15)
    basex = 0
    # events
    while True:
        for event in pygame.event.get():
            if event.type == QUIT or (event.type == KEYDOWN and event.key == K_ESCAPE):
                pygame.quit()
                sys.exit()
            elif event.type == KEYDOWN and (event.key == K_UP or event.key == K_SPACE):
                return
            else:
                screen.blit(sprites['background'], (0, 0))
                screen.blit(sprites['player'], (playerx, playery))
                screen.blit(sprites['message'], (messagex, messagey))
                screen.blit(sprites['base'], (basex, groundy))
                pygame.display.update()
                fpsclock.tick(FPS)


def maingame():
    score = 0
    playerx = int(SCREENWIDTH / 5)
    playery = int(SCREENHEIGHT/2)
    basex = 0

    newpipe1 = getrandompipe()
    newpipe2 = getrandompipe()

    upperpipe = [
        {'x': SCREENWIDTH + 200, 'y': newpipe1[0]['y']},
        {'x': SCREENWIDTH + 200 + (SCREENWIDTH / 2), 'y': newpipe2[0]['y']},
    ]

    lowerpipe = [
        {'x': SCREENWIDTH + 200, 'y': newpipe1[1]['y']},
        {'x': SCREENWIDTH + 200 + (SCREENWIDTH / 2), 'y': newpipe2[1]['y']},
    ]

    pipevelox = -4
    playerveloy = -9
    playerMaxvloy = 10
    playerMinvloy = -8
    playerAccy = 1

    playerflapAcc = -8  # velocity while flapping
    playerflapped = False

    while True:
        for event in pygame.event.get():
            if event == QUIT or (event.type == KEYDOWN and event.key == K_ESCAPE):
                pygame.quit()
                sys.exit()
            if event.type == KEYDOWN and (event.key == K_SPACE or event.key == K_UP):
                if playery > 0:
                    playerveloy = playerflapAcc
                    playerflapped = True
                    sound['wing'].play()

        crashtest = iscollide(playerx, playery, upperpipe, lowerpipe)
        if crashtest:
            return

        # scoring
        playermidpos = playerx + int(sprites['player'].get_width())/2
        for pipe in upperpipe:
            pipemidpos = pipe['x'] + (sprites['pipe'][0].get_width()/2)
            if pipemidpos <= playermidpos < pipemidpos + 4:
                score += 1
                print(f'your score is {score}')
                sound['point'].play()

        if playerveloy < playerMaxvloy and not playerflapped:
            playerveloy += playerAccy

        if playerflapped:
            playerflapped = False  # if flapped once then player has to flap again and again

        playerheight = sprites['player'].get_height()
        playery = playery + min(playerveloy, groundy - playery - playerheight)

        # to move pipes
        for up, lp in zip(upperpipe, lowerpipe):
            up['x'] += pipevelox
            lp['x'] += pipevelox

        # to add a new pipe when existing pipe is about to end
        if 0 < upperpipe[0]['x'] < 5:
            newpipe = getrandompipe()
            upperpipe.append(newpipe[0])
            lowerpipe.append(newpipe[1])

        # to remove the existing pipe
        if upperpipe[0]['x'] < -sprites['pipe'][0].get_width()/2:
            upperpipe.pop(0)
            lowerpipe.pop(0)

        # blit the sprites in game
        screen.blit(sprites['background'], (0, 0))
        for up, lp in zip(upperpipe, lowerpipe):
            screen.blit(sprites['pipe'][0], (up['x'], up['y']))
            screen.blit(sprites['pipe'][1], (lp['x'], lp['y']))
        screen.blit(sprites['player'], (playerx, playery))
        screen.blit(sprites['base'], (basex, groundy))
        # blitting the score
        mydigits = [int(x) for x in list(str(score))]
        width = 0
        for digits in mydigits:
            width += sprites['number'][digits].get_width()

        xoffset = (SCREENWIDTH - width)/2

        for digit in mydigits:
            screen.blit(sprites['number'][digit], (xoffset, SCREENHEIGHT*0.12))
            xoffset += sprites['number'][digit].get_width()
        pygame.display.update()
        fpsclock.tick(FPS)


def iscollide(playerx, playery, upperpipe, lowerpipe):
    if playery > groundy-25 or playery < 0:
        sound['hit'].play()
        return True
    for pipe in upperpipe:
        pipeheight = sprites['pipe'][0].get_height()
        if (playery < pipeheight + pipe['y']) and (abs(playerx - pipe['x']) < sprites['pipe'][0].get_width()):
            sound['hit'].play()
            return True
    
    for pipe in lowerpipe:
        if (playery + sprites['player'].get_height()) > pipe['y'] and (abs(playerx - pipe['x']) < sprites['pipe'][0].get_width()):
            sound['hit'].play()
            return True

def getrandompipe():
    pipeheight = int(sprites['pipe'][0].get_height())
    offset = int(SCREENHEIGHT/3)
    y2 = offset + \
        random.randrange(
            0, (SCREENHEIGHT - int(sprites['base'].get_height()) - 1.2*offset))
    pipex = SCREENWIDTH + 10
    y1 = pipeheight - y2 + offset
    pipecords = [
        {'x': pipex, 'y': -y1},
        {'x': pipex, 'y': y2}
    ]
    return pipecords


if __name__ == "__main__":
    pygame.init()  # initialises all pygame modules
    fpsclock = pygame.time.Clock()  # controls fps of game
    pygame.display.set_caption("Flappy Bird By Paramveer")

    # images
    sprites['number'] = (
        pygame.image.load('gallery/sprites/0.png').convert_alpha(),
        pygame.image.load('gallery/sprites/1.png').convert_alpha(),
        pygame.image.load('gallery/sprites/2.png').convert_alpha(),
        pygame.image.load('gallery/sprites/3.png').convert_alpha(),
        pygame.image.load('gallery/sprites/4.png').convert_alpha(),
        pygame.image.load('gallery/sprites/5.png').convert_alpha(),
        pygame.image.load('gallery/sprites/6.png').convert_alpha(),
        pygame.image.load('gallery/sprites/7.png').convert_alpha(),
        pygame.image.load('gallery/sprites/8.png').convert_alpha(),
        pygame.image.load('gallery/sprites/9.png').convert_alpha(),
    )
    sprites['message'] = (pygame.image.load(
        'gallery/sprites/message.png').convert_alpha())
    sprites['base'] = (pygame.image.load(
        'gallery/sprites/base.png').convert_alpha())
    sprites['pipe'] = (pygame.transform.rotate(pygame.image.load(
        pipe).convert_alpha(), 180), pygame.image.load(pipe).convert_alpha())
    sprites['background'] = (pygame.image.load(background).convert_alpha())
    sprites['player'] = (pygame.image.load(player).convert_alpha())

    # sounds---we can play these
    sound['die'] = pygame.mixer.Sound('gallery/audio/die.wav')
    sound['hit'] = pygame.mixer.Sound('gallery/audio/hit.wav')
    sound['point'] = pygame.mixer.Sound('gallery/audio/point.wav')
    sound['swoosh'] = pygame.mixer.Sound('gallery/audio/swoosh.wav')
    sound['wing'] = pygame.mixer.Sound('gallery/audio/wing.wav')

while True:
    welcomescreen()
    maingame()
