library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity wire_logic is
    Port ( sw : in STD_LOGIC;
           led : out STD_LOGIC);
end wire_logic;

architecture Behavioral of wire_logic is

begin

led <= sw;

end Behavioral;
