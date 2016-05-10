/*******************************************************************************
    Copyright 2005 Blue Inspiration Technologies. All Rights Reserved.
    chal_jamison@yahoo.com
    
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*******************************************************************************/
//

void Text::printToColumn(char *buffer, int lineWidth, String *header, String *string1, String *string2, String *string3, String *string4)
{
    //There are 9 extra formatter chars fromm the " | " string between each column... this leaves 71 chars per line divided by 4 = 17 chars per line

    const unsigned int columnWidth = 17;

    unsigned int numSpaces, i;

    // string1
    strcpy(buffer, header);

    if(strlen(string1) + strlen(header) > columnWidth)
    {
        strncat(buffer, string1, columnWidth-3);
        strcat(buffer, "...");
        numSpaces = 0;
    }
    else
    {
        strcat(buffer, string1);
        numSpaces = columnWidth - strlen(header) - strlen(string1);
    }
    for(i = 0; i < numSpaces; i++)
        strcat(buffer, " ");
    strcat(buffer, " | ");

    // string2
    strcat(buffer, header);
    if(strlen(string2) + strlen(header) > columnWidth)
    {
        strncat(buffer, string2, columnWidth-3);
        strcat(buffer, "...");
        numSpaces = 0;

    }
    else
    {
        strcat(buffer, string2);
        numSpaces = columnWidth - strlen(header) - strlen(string2);

    }
    for(i = 0; i < numSpaces; i++)
        strcat(buffer, " ");

    strcat(buffer, " | ");

    // string3
    strcat(buffer, header);
    if(strlen(string3) + strlen(header) > columnWidth)
    {
        strncat(buffer, string3, columnWidth-3);
        strcat(buffer, "...");
        numSpaces = 0;

    }
    else
    {
        strcat(buffer, string3);
        numSpaces = columnWidth - strlen(header) - strlen(string3);
    }
    for(i = 0; i < numSpaces; i++)
        strcat(buffer, " ");
    strcat(buffer, " | ");

    // string4
    strcat(buffer, header);
    if(strlen(string4) + strlen(header) > columnWidth)
    {
        strncat(buffer, string4, columnWidth-3);
        strcat(buffer, "...");
        numSpaces = 0;

    }
    else
    {
        strcat(buffer, string4);
        numSpaces = columnWidth - strlen(header) - strlen(string4);
    }
    for(i = 0; i < numSpaces; i++)
        strcat(buffer, " ");

    strcat(buffer, "\n");
}