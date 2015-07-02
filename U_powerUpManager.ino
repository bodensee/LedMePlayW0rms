class PowerUpManager
{
    private:
        Point positions[24];
        int powerUpCount;
        int powerUpLimit;
        int tickCounter;
        int tickThreshold;
        
    public:
        PowerUpManager();
        void spawnPowerUp(Worm &player1, Worm &player2);
        void tick(Worm &player1, Worm &player2);
        void tryPlayer(Worm player);     

};

PowerUpManager::PowerUpManager()
{
     powerUpCount  = 0;
     powerUpLimit  = 24;
     tickCounter   = 0;
     tickThreshold = 500;
}

void PowerUpManager::spawnPowerUp (Worm &player1, Worm &player2)
{
    if (powerUpCount < powerUpLimit)
    {
        Point point;
            
        do
        {
            int x = rand() % 31;
            int y = rand() % 31;
            point = { x, y };
            
            dbg(F("Powerup position conflict"));
        }
        while (player1.pointIsOnWorm(point) || player2.pointIsOnWorm(point));
        
        positions[powerUpCount] = point;
        ++powerUpCount;

        _P_BLUE(point.x, point.y);
    }
}

void PowerUpManager::tick(Worm &player1, Worm &player2)
{
    ++tickCounter;
    
    if (tickCounter >= tickThreshold)
    {
        tickCounter = 0;
        
        spawnPowerUp(player1, player2);
    }
}

void PowerUpManager::tryPlayer (Worm player)
{
    
}
