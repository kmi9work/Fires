using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Fire_forecast
{
    class Rules
    {
        public string name;
        public double sup;
        public int layer;
        public string fire_name;

        public Rules(string name, double sup, int layer, string fire_name)
        {
            this.name = name;
            this.sup = sup;
            this.layer = layer;
            this.fire_name = fire_name;
        }
    }

    class Terms_list
    {
        public string name;
        public double sup;

        public Terms_list(string name)
        {
            this.name = name;
            this.sup = 0;
        }
    }

    class Fires_list
    {
        public string name;  

        public Fires_list(string name)
        {
            this.name = name;
        }
    }


    class Elements
    {
        public string name;
        public double sup;
        public int layer;
        public string fire_name;

        public Elements(string name, double sup, int layer,string fire_name)
        {
            this.name = name;
            this.sup = sup;
            this.layer = layer;
            this.fire_name = fire_name;
        }

    }
    

}
